#include <iostream>
#include <vector>
#include <string>

#include "DoubleHash.h"
#define IDTYPE int


/**
 *  Base class that provides unique ids for each instantiation of class.
 */
class INode
{
public:
    static IDTYPE nextId;
    IDTYPE id;
public:
    INode() : id(nextId++) {}
    virtual ~INode() {}
};
IDTYPE INode::nextId = 0;



/**
 *  Represents a file that points to data.
 */
class FileINode : public INode
{
private:
    std::string data;
    unsigned int size;
public:
    // Constructor and destructors.
    FileINode() : INode(), size(0), data("") {}
    FileINode(std::string inString) 
        : INode(), data(inString), size(inString.size()) {}
    virtual ~FileINode() {}

    std::string& getData() { return data; }
    unsigned int getSize() const { return size; }
    void write(std::string inData)
    { 
        data = inData; 
        size = inData.size(); 
    } 
};



/**
 *  Represents a file that points to other files.
 *  
 *  Description of members:
 *  (1) Has a list of numerical inodes for files.
 *  (2) Has a list of numerical inodes for directories.
 *  (3) Has a HashMap for names for (1)
 *  (4) Has a HashMap for names for (2)
 *  (5) Has a pointer to its parent.
 * 
 *  Description of functions:
 *  (1) Is able to create a file as a child.
 *  (2) Is able to create a directory as a child, and sets that child's parent to this.
 */
class DirINode : public INode
{
private:
    DirINode* parent;

    std::vector<FileINode> files;
    DoubleHash<IDTYPE, std::string> fileNames;

    std::vector<DirINode> dirs;
    DoubleHash<IDTYPE, std::string> dirNames;
public:
    // Constructor and destructor.
    DirINode() : INode(), parent(nullptr) {} 
    virtual ~DirINode() {}


    // Some auxiliary getter-setter functions.
    DirINode* getParent() { return parent; }
    void setParent(DirINode* inParent) { parent = inParent; }
    std::vector<FileINode>& getFiles() { return files; }
    std::vector<DirINode>& getDirs() { return dirs; }
    DoubleHash<IDTYPE, std::string>& getFileNames() { return fileNames; }
    DoubleHash<IDTYPE, std::string>& getDirNames() { return dirNames; }
    

    /**
     *  Adds file to list of INodes.
     *  Adds name to HashMap so that given INode matches to that name.
     */
    void addFile(std::string name, FileINode file)
    {
        files.push_back(file);
        fileNames.insert(std::pair<IDTYPE, std::string>{file.id, name});
    }


    /**
     *  Sets given directory's parent to this directory.
     *  Adds directory to list of INodes.
     *  Adds name to Hashmap so that given INode matches to that name.
     */
    void addDir(std::string name, DirINode dir)
    {
        dir.setParent(this);
        dirs.push_back(dir);
        dirNames.insert(std::pair<IDTYPE, std::string>{dir.id, name});
    }


    // Overloaded std::ostream insertion operator.
    friend std::ostream& operator<<(std::ostream& os, const DirINode& dir)
    {
        // Print all the directories.
        for (const DirINode& d : dir.dirs) {
            os << d.id << "\tdir\t" << dir.dirNames[d.id] << std::endl;
        }
        // Print all the files.
        for (const FileINode& f : dir.files) {
            os << f.id << "\tfile\t" << f.getSize() << "\t" << dir.fileNames[f.id] << std::endl;
        }
        return os;
    }
};



/**
 *  Representation of a user that is able to maneuver around this so-called
 *  "filesystem" and manipulate it.
 */
class User
{
private:
    // `root` is so that `User` is able to return to where it began.
    DirINode* root;
    DirINode* cwd;
public:
    User(DirINode& inCwd) : root(&inCwd), cwd(&inCwd) {}


    /**
     *  Creates an empty directory in the cwd.
     */
    void mkdir(std::string name)
    { 
        // Ensure that directory doesn't already exist.
        DoubleHash<IDTYPE, std::string>& cwdDirNames = cwd->getDirNames();
        for (DirINode& d : cwd->getDirs())
        {
            if (name == cwdDirNames[d.id])
            {
                std::cerr << name << " already exists." << std::endl;
                return;
            }
        }
        
        // If it doesn't, create it!
        DirINode dir;
        cwd->addDir(name, dir);
    }


    /**
     *  Creates an empty file in the cwd.
     */
    void touch(std::string name)
    {
        // Ensure that file doesn't already exist.
        DoubleHash<IDTYPE, std::string>& cwdFileNames = cwd->getFileNames();
        for (FileINode& f : cwd->getFiles())
        {
            if (name == cwdFileNames[f.id])
            {
                std::cerr << name << " already exists." << std::endl;
                return;
            }
        }

        // If it doesn't, create it!
        FileINode file;
        cwd->addFile(name, file);
    }


    /**
     *  Returns true if `cd` was successful.
     *  Returns false if `name` is not found in child directories.
     */
    bool cd(std::string name)
    {
        // Return to parent.
        if (name == "..")
        {
            if (cwd->getParent() != nullptr)
            {
                cwd = cwd->getParent();
                return true;
            }
        
        // Do nothing.
        } else if (name == ".") {
            return true;
        
        // Search through numerical inodes and their names and check if a match is made.
        } else {
            DoubleHash<IDTYPE, std::string>& cwdDirNames = cwd->getDirNames();
            for (DirINode& d : cwd->getDirs())
            {
                if (name == cwdDirNames[d.id])
                {
                    cwd = &d;
                    return true;
                }
            }
            return false;
        }
    }


    /**
     *  Writes given contents to `filename` if `filename` exists in the cwd.
     */
    bool write(std::string filename, std::string data)
    {
        DoubleHash<IDTYPE, std::string>& cwdFileNames = cwd->getFileNames();
        for (FileINode& f : cwd->getFiles())
        {
            if (filename == cwdFileNames[f.id])
            {
                // Found the file! Write to it and return early.
                f.write(data);
                return true;
            }
        }
        return false;
    }


    /**
     *  Prints contents of `filename` if `filename` exists in the cwd.
     */
    void cat(std::string filename)
    {
        DoubleHash<IDTYPE, std::string>& cwdFileNames = cwd->getFileNames();
        for (FileINode& f : cwd->getFiles())
        {
            if (filename == cwdFileNames[f.id])
            {
                std::cout << "[Contents of file " << filename << "]" << std::endl;
                std::cout << f.getData() << std::endl << std::endl;
                return;
            }
        }
        std::cerr << filename << " does not exist." << std::endl;
    }


    // Returns cwd to where `User` was initialized.
    void cd()
    {
        cwd = root;
    }


    /**
     *  Prints out contents of the `cwd`.
     */
    void ls()
    {
        if (cwd->getParent() == nullptr) {
            std::cout << "Contents of dir /" << std::endl;
        } else {
            std::cout << "Contents of dir " << cwd->getParent()->getDirNames()[cwd->id] << std::endl;
        }
        std::cout << (*cwd) << std::endl;
    }

};