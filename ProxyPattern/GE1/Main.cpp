
// Robin Meyler 08/10/2020
// Game Engineering 2: Lab 1

#include <iostream>
#include <vector>

//Abstract class
class Character {
public:
	Character() {}
	~Character() {
	}
	virtual void draw() = 0;	// Pure virtual
};

class Dog : public Character {
public:
	Dog() {}

	virtual void draw() 
	{
		std::cout << "Bark" << std::endl;
	}
};

class Bird : public Character {
public:
	Bird() {}
	virtual void draw()
	{
		std::cout << "Chirp" << std::endl;
	}
};


class Alien : public Character {
public:
	Alien() {}
	virtual void draw()
	{
		std::cout << "Hissssss" << std::endl;
	}
};

class Factory {
	virtual void createDog() = 0;
	virtual void createBird() = 0;
	virtual void createAlien() = 0;
};

class FactoryCollection {
public:
	virtual Character* createDog() {
		return new Dog();
	}
	virtual Character* createBird() {
		return new Bird();
	}
	virtual Character* createAlien() {
		return new Alien();
	}
};

class CharacterProxy : Character
{
public:
	CharacterProxy()
	{
		m_characterFactory = new FactoryCollection();
	}
	~CharacterProxy()
	{
		if (m_characterFactory)
		{
			delete m_characterFactory;
		}
		for (auto& characts : m_characters)
		{
			delete characts;
		}
		m_characters.clear();
	}

	void makeDog()
	{
		m_characters.push_back(m_characterFactory->createDog());
	}
	void makeBird()
	{
		m_characters.push_back(m_characterFactory->createBird());
	}
	void makeAlien()
	{
		m_characters.push_back(m_characterFactory->createAlien());
	}

	void draw()
	{
		this->getCharacterInstances();
		for (auto &chacts : m_characters)
		{
			chacts->draw();
		}
	}


private:
	FactoryCollection* m_characterFactory;
	std::vector<Character*> m_characters;

	FactoryCollection* getCharacterInstances(void)
	{
		if (!m_characterFactory)
		{
			m_characterFactory = new FactoryCollection();
		}
		return m_characterFactory;
	}
};

int main()
{
	CharacterProxy chpxy;

	chpxy.makeBird();
	chpxy.makeAlien();
	chpxy.makeDog();
	chpxy.makeBird();
	chpxy.draw();
	
	system("PAUSE");
	return 0;
}