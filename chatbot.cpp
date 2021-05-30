#include <bits/stdc++.h>
#include <windows.h>

using namespace std;
int main()
{
    string phrase = "hello world how are you?";
    string command = "espeak -v +f3  \""+phrase+"\"";
    const char* charCommand = command.c_str();
    system(charCommand);
    return 0;
}
