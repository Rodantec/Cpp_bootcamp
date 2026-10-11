#include "Fixed.hpp"

int main( void ) 
{
    std::cout << "=== TEST ORIGINAL ===" << std::endl;
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;

    std::cout << "\n=== TESTS DES OPÉRATEURS DE COMPARAISON ===" << std::endl;
    Fixed x(10.5f);
    Fixed y(5.25f);
    Fixed z(10.5f);

    std::cout << "x = " << x << ", y = " << y << ", z = " << z << std::endl;
    std::cout << "x > y  : " << (x > y) << " (attendu: 1)" << std::endl;
    std::cout << "x < y  : " << (x < y) << " (attendu: 0)" << std::endl;
    std::cout << "x >= z : " << (x >= z) << " (attendu: 1)" << std::endl;
    std::cout << "x <= z : " << (x <= z) << " (attendu: 1)" << std::endl;
    std::cout << "x == z : " << (x == z) << " (attendu: 1)" << std::endl;
    std::cout << "x != y : " << (x != y) << " (attendu: 1)" << std::endl;

    std::cout << "\n=== TESTS DES OPÉRATEURS ARITHMÉTIQUES ===" << std::endl;
    Fixed num1(10.0f);
    Fixed num2(3.0f);

    std::cout << "num1 = " << num1 << ", num2 = " << num2 << std::endl;
    std::cout << "num1 + num2 = " << (num1 + num2) << " (attendu: 13)" << std::endl;
    std::cout << "num1 - num2 = " << (num1 - num2) << " (attendu: 7)" << std::endl;
    std::cout << "num1 * num2 = " << (num1 * num2) << " (attendu: 30)" << std::endl;
    std::cout << "num1 / num2 = " << (num1 / num2) << " (attendu: ~3.33)" << std::endl;

    std::cout << "\n=== TESTS DES OPÉRATEURS D'INCRÉMENTATION ===" << std::endl;
    Fixed counter(5.0f);
    
    std::cout << "Valeur initiale: " << counter << std::endl;
    std::cout << "++counter: " << ++counter << std::endl;
    std::cout << "Après ++: " << counter << std::endl;
    std::cout << "counter++: " << counter++ << std::endl;
    std::cout << "Après ++: " << counter << std::endl;

    std::cout << "\n=== TESTS DES OPÉRATEURS DE DÉCRÉMENTATION ===" << std::endl;
    Fixed down(5.0f);
    
    std::cout << "Valeur initiale: " << down << std::endl;
    std::cout << "--down: " << --down << std::endl;
    std::cout << "Après --: " << down << std::endl;
    std::cout << "down--: " << down-- << std::endl;
    std::cout << "Après --: " << down << std::endl;

    std::cout << "\n=== TESTS DES FONCTIONS MIN/MAX ===" << std::endl;
    Fixed p(42.42f);
    Fixed q(21.21f);
    
    std::cout << "p = " << p << ", q = " << q << std::endl;
    std::cout << "Fixed::min(p, q) = " << Fixed::min(p, q) << std::endl;
    std::cout << "Fixed::max(p, q) = " << Fixed::max(p, q) << std::endl;

    // Test avec const
    Fixed const cp(100.5f);
    Fixed const cq(50.25f);
    std::cout << "const p = " << cp << ", const q = " << cq << std::endl;
    std::cout << "Fixed::min(cp, cq) = " << Fixed::min(cp, cq) << std::endl;
    std::cout << "Fixed::max(cp, cq) = " << Fixed::max(cp, cq) << std::endl;

    std::cout << "\n=== TEST COMPLEXE ===" << std::endl;
    Fixed result = (Fixed(10) + Fixed(5)) * Fixed(2) / Fixed(3);
    std::cout << "(10 + 5) * 2 / 3 = " << result << " (attendu: 10)" << std::endl;

    return 0;
}