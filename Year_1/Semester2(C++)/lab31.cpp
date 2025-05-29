#include <iostream>
#include <string>

class HTMLElement
{
private:
  std::string tagName;
  std::string content;

public:
  // Constructor
  HTMLElement(std::string input)
  {
    // Find the first '<' and '>' to get the tagName
    size_t startTagOpen = input.find('<');
    size_t startTagClose = input.find('>');

    if (startTagOpen != std::string::npos && startTagClose != std::string::npos)
    {
      tagName = input.substr(startTagOpen + 1, startTagClose - startTagOpen - 1);
    }

    // Find the closing tag
    std::string endTag = "</" + tagName + ">";
    size_t endTagStart = input.find(endTag);

    if (endTagStart != std::string::npos)
    {
      // Content is between the end of the opening tag and the start of the closing tag
      content = input.substr(startTagClose + 1, endTagStart - startTagClose - 1);
    }
  }

  std::string getTagName()
  {
    return tagName;
  }

  std::string getContent()
  {
    return content;
  }
};

int main() {
  std::string str;
  std::getline(std::cin, str);
  HTMLElement html(str);
  std::cout << html.getTagName() << std::endl;
  std::cout << html.getContent() << std::endl;
  return 0;
}
