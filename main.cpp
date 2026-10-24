#include "holiday.h"

int main(){
    const int n{4};
    using namespace SehyunKu2693015;
    holiday a[n];
    a[0] = holiday{"Christmas", dayOfYear{12,25}, false};
    a[0].print();

}