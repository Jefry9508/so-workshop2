#include <stdio.h>
#include <linux/kernel.h>
#include <linux/sys.h>
#include <sys/sysinfo.h>
int main ()
{
    const long minutos = 60;
    const long horas   = minutos * 60;
    const long dia    = horas * 24;
    const double megabyte = 1024 * 1024;
    struct sysinfo si;
    /* Obtenemos estadísticas del sistema */
    sysinfo(&si);
    /* Mostramos algunos valores interesantes contenidos en la estructura sysinfo. */
    printf("Tiempo que lleva el sist. en funcionamiento: %ld dia , %ld:%02ld:%02ld\n”,
        si.uptime/dia,
        (si.uptime % dia) / horas,
        (si.uptime % horas) / minutos,
         si.uptime % minutos);
    printf("Memoria RAM total: %5.1f Mb\n" , si.totalram / megabyte);
    printf("Memoria RAM libre: %5.1f Mb\n" , si.freeram / megabyte);
    printf("Cantidad de procesos corriendo: %d\n" , si.procs);
    return 0;
}