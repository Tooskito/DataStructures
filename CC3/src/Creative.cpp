#include <string>
#include "../include/Filesystem.h"

int main()
{
    // create root directory
    DirINode root;
    User user(root);

    // create some directories.
    user.mkdir("bin");
    user.mkdir("dev");
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

    // move into home directory and make some stuff.
    user.cd("home");
    user.mkdir("jonathanabbott");
    user.mkdir("aliceinwonderland");
    user.mkdir("thekoolaidman");
    user.mkdir("peaceteajustpeachy");
    user.mkdir("ayylmao");
    user.ls();

    // move into personal directory and wreak havoc.
    user.cd("jonathanabbott");
    user.touch("hello.txt");
    user.write("hello.txt", "Hello, and welcome to my UNIX filesystem!\nFair warning: it's all in memory! Don't turn off your computer...");
    user.touch("omgdonotreadme.md");
    user.write("omgdonotreadme.md", "ayy lmao you read this anyway you a real one");
    user.ls();

    // print out the contents of these files.
    user.cat("hello.txt");
    user.cat("omgdonotreadme.md");

    // overwrite a file.
    user.write("hello.txt", "I have been overwritten, oh no!");
    user.ls();
    user.cat("hello.txt");

    return 0;
}