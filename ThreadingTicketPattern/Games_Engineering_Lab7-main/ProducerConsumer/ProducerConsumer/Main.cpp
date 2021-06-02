
#include <iostream>
#include <string>
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
	int ticketNumber;
};

std::queue<Burger> burgers;			// Queue to manage ordering of the burgers (So none go cold)
const int MAX_BURGERS = 5;			// Max burgers alowed in the slot
std::mutex ProducerLock;			// To manage Prodcuer
std::mutex ConsumerLock;			// To manage Consumer
int consumerTicket = 0;
int producerTicket = 0;

void Produce(int id)
{
	// Never stop
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::seconds((rand() % 50)/10));		// Creation of burger time		
		
		if (burgers.size() < MAX_BURGERS)
		{
			int type = (rand() % 3);
			Burger burger;
			if (type == 0)
				burger.type = "Cheese";
			else if (type == 1)
				burger.type = "Bacon";
			else if (type == 2)
				burger.type = "Plain";

			ProducerLock.lock();									// Lock before reading the value since burgers/cout might be affected else where, lock guard expires at the end of the scope
			burger.ticketNumber = (producerTicket % 1000);
			producerTicket++;
			burgers.push(burger);
			ProducerLock.unlock();
			std::cout << "Burger Ticket Num: " << std::to_string(burger.ticketNumber) << std::endl;
		}
	}
}

void consume(int id)
{
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::seconds((rand() % 50)/10));			// Random time between customers

		int myTicketNumber = consumerTicket % 1000;
		consumerTicket++;
		std::cout << "Consumer Ticket Num: " << std::to_string(myTicketNumber) << std::endl;

		bool wait = true;
		while (wait == true)
		{
			ConsumerLock.lock();
			if (burgers.size() > 0 && burgers.front().ticketNumber == myTicketNumber)
			{
				burgers.pop();										// Remove the burger from the queue
				wait = false;
			}
			ConsumerLock.unlock();
		}
		std::cout << "Ticket Matched " << std::to_string(myTicketNumber) << std::endl;
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

