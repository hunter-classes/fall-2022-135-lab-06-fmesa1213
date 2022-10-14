#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

TEST_CASE("C"){
 CHECK("Hello, World" == "Jevpq, Wyvnd!");
   CHECK("good night" == "ioyh piqlv");
   CHECK("good morning" == "ioyh oobrknq");
//keyword == cake

}
       
TEST_CASE("D"){

 CHECK(
 = Caesar =
Enter shift    : 10
Ciphertext     : qyyn xsqrd
Decrypted      : good night

= Vigenere =
Enter keyword  : cake
Ciphertext     : ioyh piqlv
Decrypted      :good night

 );
   CHECK(
   = Caesar =
Enter shift    : 10
Ciphertext     : qyyn wybxsxq
Decrypted      : good morning


= Vigenere =
Enter keyword  : cake
Ciphertext     : ioyh oobrknq
Decrypted      :good morning


   );
   CHECK(= Caesar =
Enter shift    : 10
Ciphertext     : Rovvy, Gybvn!
Decrypted      : Hello, World!

= Vigenere =
Enter keyword  : cake
Ciphertext     : Jevpq, Wyvnd!
Decrypted      : Hello, World!
);
}
       
