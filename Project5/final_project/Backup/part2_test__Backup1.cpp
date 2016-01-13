#include "Service_Center.h"

int main()
{
    Service_Center *center = new Service_Center();
    center->menu();
    delete center;
    return 0;
}
