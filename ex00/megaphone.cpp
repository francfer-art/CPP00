#include <iostream> // Allows me to use cout cin
#include <cctype> // Allows me to use functions like isalfa or toupper

void  print_elem(char *c) {
  while (*c) {
    std::cout << (char)std::toupper(*c);
    c++;
  }
}
int main(int args, char **argv) {

  if (args == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
  } else {
    argv++;
    while(*argv) {
      print_elem(*argv);
      argv++;
    }
    std::cout << std::endl;
  }

  return 0;
}