
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <shared_mutex>
#include <vector>
#include <queue>
#include <ctime>

const int MAX = 5;
int producerCount = 0;
int consumerCount = 0;
int buffer = 0;
std::mutex Prodlock;
std::mutex Conlock;

// Single Producer Consumer - Esentially linear

void ProducerSingle()
{
	int a[MAX] = { 10,20,30,40,50 };
	bool run = true;
	
	while (run)
	{
		std::this_thread::sleep_for(std::chrono::seconds(2));
		while (producerCount != consumerCount)
		{
			// Wait for Consumption
		}
		std::cout << "Locking Producer" << std::endl;
		Prodlock.lock();								// Don't really serve a purpose as there is only 1 thread
		buffer = a[producerCount % 5];
		std::cout << a[producerCount % 5] << " depositited in buffer for consumption" << std::endl;
		producerCount = producerCount + 1;
			
		std::cout << "Unlocking Producer\n" << std::endl;
		Prodlock.unlock();
	}
}


void ConsumerSingle()
{
	int b[MAX];
	bool run = true;
	while (run)
	{
	
		std::this_thread::sleep_for(std::chrono::seconds(2));
		while ((producerCount <= consumerCount))
		{
			// Wait For prduction
		}
		std::cout << "Locking Consumer" << std::endl;
		Conlock.lock();
		b[consumerCount % 5] = buffer;
		std::cout << buffer << " Consumed " <<  std::endl;
		consumerCount = consumerCount + 1;
			
		std::cout << "Unlocking Consumer\n" << std::endl;
		Conlock.unlock();
	}
}


// Muliple Prodcuer consumer with random wait times to make ths simulation more interesting
struct Burger
{
	std::string type{ "Unmade" };
};

std::queue<Burger> burgers;			// Queue to manage ordering of the burgers (So none go cold)
const int MAX_BURGERS = 5;			// Max burgers alowed in the slot
std::mutex ProducerLock;			// To manage Prodcuer
std::mutex ConsumerLock;			// To manage Consumer

void Produce(int id)
{
	// Never stop
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::seconds((rand() % 50)/10));		// Creation of burger time
		// std::lock_guard<std::mutex> guard(ProducerLock);				
		ProducerLock.lock();									// Lock before reading the value since burgers/cout might be affected else where, lock guard expires at the end of the scope
		if (burgers.size() < MAX_BURGERS)
		{
			std::cout << "Burgers: " << burgers.size() << std::endl;;
			std::cout << "Producer ID: " << id << " ---ADD\n";
			int type = (rand() % 3);
			Burger burger;
			if (type == 0)
				burger.type = "Cheese";
			else if (type == 1)
				burger.type = "Bacon";
			else if (type == 2)
				burger.type = "Plain";
			burgers.push(burger);
		}
		else
		{
			std::cout << "Full of burgers :)\n";
		}
		ProducerLock.unlock();
		// Lock guard is released here as it goes out of scope
	}
}

void consume(int id)
{
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::seconds((rand() % 50)/10));			// Random time between customers
		//std::lock_guard<std::mutex> guard(ConsumerLock);				
		ConsumerLock.lock();									// Lock before reading the value since burgers/cout might be affected else where, lock guard expires at the end of the scope
		if (burgers.size() > 0)
		{
			std::cout << "Burgers: " << burgers.size() << std::endl;
			std::cout << "Consumer ID: " << id << " ---REMOVE " << "-- Burger Type : " << burgers.front().type << " \n";
			burgers.pop();		// Remove the burger from the queue
		}
		else
		{
			std::cout << "Need new burger :(\n";
		}
		ConsumerLock.unlock();
	}
}




int main()
{
	srand(time(nullptr));

	// Single Producer Consumer

	//std::thread producer(ProducerSingle);
	//std::thread consumer(ConsumerSingle);

	//producer.join();
	//consumer.join();

	// Multiple Producer Consumer

	std::thread prod1(Produce, 1);
	std::thread prod2(Produce, 2);
	std::thread prod3(Produce, 3);
	std::thread prod4(Produce, 4);

	std::thread consumer1(consume, 1);
	std::thread consumer2(consume, 2);
	std::thread consumer3(consume, 3);
	std::thread consumer4(consume, 4);

	prod1.join();
	prod2.join();
	prod3.join();
	prod4.join();
	consumer1.join();
	consumer2.join();
	consumer3.join();
	consumer4.join();

	std::cin.get();

	return 1;
}

