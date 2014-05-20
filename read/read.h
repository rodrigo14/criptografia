#ifndef READ_H
#define READ_H

#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

using namespace std;

struct passwd *pw = getpwuid(getuid());
string homedir = pw->pw_dir;
string path = "/Dropbox/Criptografia/trab1/files/";

#endif