/**
 *  @author Jonathan Abbott
 *  @date   Sep 13, 2020
 * 
 *  Includes tests for `Filesystem.h`, my creative application for CC3 for CSE 20312.
 */


#include <string> // So "" turns into std::string and not cstr.
#include "../include/Filesystem.h"


/**
 *  The driver for my creative portion of CC3.
 *  @return An exit code.
 */
int main()
{
    // Initialize root directory and initialize user to root.
    DirINode root;
    User user(root);

    // Test one, make some directories.
    std::cout << std::endl << "-=- TEST ONE -=- MAKE SOME DIRECTORIES -=-" << std::endl;
    user.mkdir("bin");
    user.mkdir("dev"); //rsd
    user.mkdir("etc");
    user.mkdir("home");
    user.mkdir("lib");
    user.mkdir("mnt");
    user.mkdir("proc");
    user.mkdir("root");
    user.mkdir("sbin");
    user.mkdir("tmp");
    user.mkdir("usr");
    user.ls();

    user.cd("home");
    user.mkdir("jonathanabbott");
    user.mkdir("aliceinwonderland");
    user.mkdir("thekoolaidman");
    user.mkdir("peaceteajustpeachy");
    user.mkdir("ayylmao");
    user.ls();

    user.cd("jonathanabbott");
    user.mkdir("DataStructures");
    user.ls();

    user.cd("DataStructures");
    user.mkdir("exe");
    user.mkdir("obj");
    user.mkdir("include");
    user.mkdir("src");
    user.ls();


    // Test two, make some files.
    std::cout << std::endl << "-=- TEST TWO -=- MAKE SOME FILES -=-" << std::endl;

    user.touch("Makefile");
    user.touch("README.md");
    user.ls();

    user.cd("src");
    user.touch("Creative.cpp");
    user.touch("DoubleTest.cpp");
    user.ls();

    {   // Jump back into DataStructures/
        user.cd();
        user.cd("home");
        user.cd("jonathanabbott");
        user.cd("DataStructures");
    }

    user.cd("include");
    user.touch("DoubleHash.h");
    user.touch("Filesystem.h");
    user.touch("LinearProbe.h");
    user.ls();

    {   // Jump back into DataStructures/
        user.cd();
        user.cd("home");
        user.cd("jonathanabbott");
        user.cd("DataStructures");
    }

    // Test three, write to those files.
    std::cout << std::endl << "-=- TEST THREE -=- WRITE TO THOSE FILES -=-" << std::endl;

    user.cd("src");

    user.write("Creative.cpp", 
        "/**\n"
        "*  @author Jonathan Abbott\n"
        "*  @date   Sep 13, 2020\n"
        "*\n"
        "*  Includes tests for `Filesystem.h`, my creative application for CC3 for CSE 20312.\n"
        "*/"
    );
    user.write("DoubleTest.cpp", "/**\n"
        "*  @author Jonathan Abbott\n"
        "*  @date   Sep 13, 2020\n"
        "*\n"
        "*  Includes tests for `DoubleHash.h` for CC3 for CSE 20312.\n"
        "*/"
    );
    user.ls();

    user.cat("Creative.cpp");
    user.cat("DoubleTest.cpp");

    user.cd();
    user.cd("home");
    user.cd("jonathanabbott");
    user.cd("DataStructures");

    user.cd("include");

    user.write("DoubleHash.h",
        "/**\n"
        "*  @author Jonathan Abbott\n"
        "*  @date   Sep 13, 2020\n"
        "*\n"
        "*  Includes declaration and definition of a double-hashing hash-table.\n"
        "*/"
    );
    user.write("Filesystem.h",
        "/**\n"
        "*  @author Jonathan Abbott\n"
        "*  @date   Sep 13, 2020\n"
        "*\n"
        "*  Includes declarations and definitions of the crucial components of a\n"
        "*  hypothetical filesystem, greatly inspired by the UNIX filesystem.\n"
        "*/"
    );
    user.write("LinearProbe.h",
        "// Code from Prof. Morrison\n"
        "// See: https://github.com/mmorri22/cse20312/blob/master/Lecture10/include/LinearProbe.h"
    );
    user.ls();

    user.cat("DoubleHash.h");
    user.cat("Filesystem.h");
    user.cat("LinearProbe.h");


    // Test four, try to create/write files and directories when they already exist.
    std::cout << std::endl << "-=- TEST FOUR -=- FILES/DIR ALREADY EXIST AND FILES DON'T EXIST -=-" << std::endl;

    user.cd(); // To go to root level directory.
    user.ls();

    user.mkdir("home");
    user.mkdir("usr");

    user.write("thisfiledoesnotexist", "ayy lmao");
    user.write("thisfilealsodoesnotexist", "thisispracticallyunreadable");


    return EXIT_SUCCESS;
}