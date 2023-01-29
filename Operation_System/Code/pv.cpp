#include <iostream>
#include <mutex>
#include <thread>
using namespace std;
#define BUFFER_CAPACITY 10

class Buffer
{
    // Buffer fields
    int buffer[BUFFER_CAPACITY];
    int buffer_size;
    int left;  // index where variables are put inside of buffer (produced)
    int right; // index where variables are removed from buffer (consumed)

    // Fields for concurrency
    std::mutex mtx;
    std::condition_variable not_empty;
    std::condition_variable not_full;

public:
    // Place integer inside of buffer
    void produce(int thread_id, int num);

    // Remove integer from buffer
    int consume(int thread_id);

    Buffer()
    {
        buffer_size = 0;
        left = 0;
        right = 0;
    }
};

void Buffer::produce(int thread_id, int num)
{
    // Acquire a unique lock on the mutex
    std::unique_lock<std::mutex> unique_lock(mtx);

    std::cout << "thread " << thread_id << " produced " << num << "\n";

    // Wait if the buffer is full
    not_full.wait(unique_lock, [this]()
                  { return buffer_size != BUFFER_CAPACITY; });

    // Add input to buffer
    buffer[right] = num;

    // Update appropriate fields
    right = (right + 1) % BUFFER_CAPACITY;
    buffer_size++;

    // Unlock unique lock
    unique_lock.unlock();

    // Notify a single thread that buffer isn't empty
    not_empty.notify_one();
}

int Buffer::consume(int thread_id)
{
    // Acquire a unique lock on the mutex
    std::unique_lock<std::mutex> unique_lock(mtx);

    // Wait if buffer is empty
    not_empty.wait(unique_lock, [this]()
                   { return buffer_size != 0; });

    // Get value from position to remove in buffer
    int result = buffer[left];

    std::cout << "thread " << thread_id << " consumed " << result << "\n";

    // Update appropriate fields
    left = (left + 1) % BUFFER_CAPACITY;
    buffer_size--;

    // Unlock unique lock
    unique_lock.unlock();

    // Notify a single thread that the buffer isn't full
    not_full.notify_one();

    // Return result
    return result;
}

// Takes in reference to a buffer and adds a random integer
void produceInt(Buffer &buffer)
{
    for (int i = 0; i < 4; i++)
    {
        // Generate random number between 1 and 10
        int new_int = rand() % 10 + 1;
        buffer.produce(i, new_int);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

// Takes in reference to a buffer and returns the latest int added
// in the buffer
void consumeInt(Buffer &buffer)
{
    for (int i = 0; i < 6; i++)
    {
        buffer.consume(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main(int argc, const char *argv[])
{
    std::cout << "Executing code in main...\n";

    // Initialize random seed
    srand(time(NULL));

    // Create Buffer
    Buffer buffer;

    // Create a thread to produce
    std::thread produceThread0(produceInt, std::ref(buffer));

    std::thread consumeThread0(consumeInt, std::ref(buffer));

    std::thread produceThread1(produceInt, std::ref(buffer));

    std::thread consumeThread1(consumeInt, std::ref(buffer));

    std::thread produceThread2(produceInt, std::ref(buffer));

    produceThread0.join();
    produceThread1.join();
    produceThread2.join();
    consumeThread0.join();
    consumeThread1.join();

    std::cout << "Done!\n";
    return 0;
}