#include <sys/types.h>
#include <sys/stat.h>

int main() {
  chmod("Prueba.txt", S_IRWXU);
}