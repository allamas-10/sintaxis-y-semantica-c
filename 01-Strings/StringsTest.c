#include "Strings.h"
#include <assert.h>

int main(){
    assert(IsEmpty("") == true);
    assert(IsEmpty("X") == false);
    assert(GetLength("") == 0);
    assert(GetLength("Hola mundo") == 10);

    assert(AreEqual("", "") == true);
    assert(AreEqual("Hola", "Holi") == false);

    assert(AreDecimalDigits("1232312f3231") == false);
    assert(AreDecimalDigits("12323123231") == true);

    assert(ToInteger("1232312f3231") == 0);
    assert(ToInteger("1232") == 1232);
    assert(ToInteger("") == 0);

    char bufferConc[20] = "Hola";
    Concatenate(bufferConc, " mundo");
    assert(AreEqual(bufferConc, "Hola mundo") == true);

    char bufferPower[20] = "vaca";
    Power(bufferPower, 3);
    assert(AreEqual(bufferPower, "vacavacavaca") == true);

    return 0;
}