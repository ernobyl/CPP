#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    //const Animal*       animal = new Animal(); this class cannot be instantiated now, but derived classes (dog, cat) can
    const WrongAnimal*  wrong = new WrongAnimal();
    const Animal*       animal_1 = new Dog();
    const WrongAnimal*  animal_2 = new WrongCat();
    const Animal*       animal_3 = new Cat();

    std::cout << "type of animal_1: " << animal_1->getType() << " " << std::endl;
    std::cout << "type of animal_2: " << animal_2->getType() << " " << std::endl;
    std::cout << "type of animal_3: " << animal_3->getType() << " " << std::endl;

    animal_1->makeSound();
    animal_2->makeSound();
    animal_3->makeSound();
    wrong->makeSound();
    //animal->makeSound();

    delete wrong;
    delete animal_1;
    delete animal_2;
    delete animal_3;
    //delete animal;

    return (0);
}

