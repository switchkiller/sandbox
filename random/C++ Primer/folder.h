#include<string.h>
#include<set>
#include<vector>

class Folder;

class Message {
  friend class Folder;
public:
  // Folder initialized to empty set automatically.
  Message(const std::string &str = "");
    contents (str) {}

}
