#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main() {

//	error Abstract class Animal
	// Animal x;

	const Animal *x = new Dog();
	const Animal *y = new Cat();
	delete x;
	delete y;
	std::cout << "***************" << std::endl;

	Animal *arr[10];

	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0)
			arr[i] = new Cat();
		else
			arr[i] = new Dog();
		std::cout << "-------------" << std::endl;
	}
	for (int i = 0; i < 10; i++) {
		delete arr[i];
		std::cout << "\n";
	}

//========================
//	Brain validation
//========================
	// Brain b;

	// try {
	// 	b.set_idea("hello", 4);
	// 	b.set_idea("hello", 991);
	// } catch (const std::out_of_range& e){
	// 	std::cerr << e.what();
	// 	return 1;
	// }

	// std::cout << 4 << " " << b[4] << "\n";
	// std::cout << 1 << " " << b[132] << "\n";
//========================


// //========================
// //	Copy constructor validation
// //========================
// 	Cat *c = new Cat();

// 	c->think("C old idea", 4);

// 	Cat b(*c);

// 	c->think("C new idean", 4);
// 	delete c;
// 	std::cout << "\n\n" << b.remember(4) << "\n\n";
// 	b.think("B new idea", 4);
// 	std::cout << "\n\n" << b.remember(4) << "\n\n";
// 	system("leaks zoo");
// //========================

//========================
//	Copy assign operation
//========================
	Cat *c = new Cat();

	c->think("C old idea", 4);

	std::cout << "\n";
	Cat b;

	b = *c;

	c->think("C new idean", 4);
	delete c;
	std::cout << "\n\n" << b.remember(4) << "\n\n";
	b.think("B new idea", 4);
	std::cout << "\n\n" << b.remember(4) << "\n\n";
	system("leaks zoo");
//========================



	


	return 0;
}