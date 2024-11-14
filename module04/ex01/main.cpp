#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    const int NUM_ANIMALS = 6;
    Animal* animals[NUM_ANIMALS];

    for (int i = 0; i < NUM_ANIMALS / 2; i++)
        animals[i] = new Dog();
    for (int i = NUM_ANIMALS / 2; i < NUM_ANIMALS; i++)
        animals[i] = new Cat();

    Dog* dog = dynamic_cast<Dog*>(animals[0]);
    if (dog && dog->getBrain())
    {
        dog->getBrain()->setIdea(0, "Chase ball");
        dog->getBrain()->setIdea(1, "Spaz out");
    }

    // Copy Dog and check if it's a deep copy
    Dog* dogCopy = new Dog(*dog);
    if (dogCopy && dogCopy->getBrain())
    {
        std::cout << "Original Dog's Idea 0: " << dog->getBrain()->getIdea(0) << std::endl;
        std::cout << "Copied Dog's Idea 0: " << dogCopy->getBrain()->getIdea(0) << std::endl;
        std::cout << "Copied Dog's Idea 1: " << dogCopy->getBrain()->getIdea(1) << std::endl;

        dog->getBrain()->setIdea(0, "Eat cardboard");
        std::cout << "Modified Original Dog's Idea 0: " << dog->getBrain()->getIdea(0) << std::endl;
        std::cout << "Unchanged Copied Dog's Idea 0: " << dogCopy->getBrain()->getIdea(0) << std::endl;
    }

    delete dogCopy;
    for (int i = 0; i < NUM_ANIMALS; i++)
        delete animals[i];

    return 0;
}
