#include "Base.hpp"

#include <cstdlib>
#include <cstdio>

static Base *generate(void)
{
	switch (rand() % 3)
	{
	case 0:
		return (new A());
		break;
	case 1:
		return (new B());
		break;
	case 2:
		return (new C());
		break;
	default:
		perror("Something went wrong with the random generator");
		return (NULL);
	}
}

static void identify(Base *Test)
{
	if (dynamic_cast<A *>(Test))
		std::cout << "A is the identified type" << std::endl;
	else if (dynamic_cast<B *>(Test))
		std::cout << "B is the identified type" << std::endl;
	else if (dynamic_cast<C *>(Test))
		std::cout << "C is the identified type" << std::endl;
	else
		std::cout << "unknown type" << std::endl;
}

static int i = 0;
static std::string classes[] = {"A", "B", "C"};

static void identify(Base &Test)
{
	while (i < 3)
	{
		//maybe it's error because all casts should be the same type
		Base foo; // only to initialize the unused var
		Base &unused = (Base &)foo; // only to prevent the -Werror from triggering for unused value of the casts
		try
		{
			if (i == 0)
				unused = dynamic_cast<A &>(Test);
			else if (i == 1)
				unused = dynamic_cast<B &>(Test);
			else if (i == 2)
				unused = dynamic_cast<C &>(Test);
			else
				std::cout << "unknow type" << std::endl;
			(void)unused;
		}
		catch (std::exception &e)
		{
			// std::cout << e.what() << std::endl; //enable to see what exception was cought
			i++;
			identify(Test);
			return;
		}
		std::cout << classes[i] << " is the identified type" << std::endl;
		i = 0;
		break;
	}
}

int main()
{
	srand(time(NULL)); // enables the randomness of the generate function
	for (int j = 0; j < 5; j++)
	{
		Base *Test = generate();
		if (Test == NULL)
			return (1);
		else
		{
			identify(Test);
			identify(*Test);
			delete (Test);

			std::cout << std::endl;
		}
	}
	return (0);
}