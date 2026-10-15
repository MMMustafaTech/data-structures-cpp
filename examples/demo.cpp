#include <iostream>
#include "clsMyQueue.h"
#include "clsMyStack.h"
#include "clsQueueLine.h"

int main() {
    clsMyQueue<int> queue;
    queue.push(10);
    queue.push(20);
    std::cout << "Queue front: " << queue.front() << '\n';

    clsMyStack<int> stack;
    stack.push(10);
    stack.push(20);
    std::cout << "Stack top: " << stack.Top() << '\n';

    clsQueueLine line("A", 5);
    line.IssueTicket();
    line.IssueTicket();
    std::cout << "Next ticket: " << line.WhoIsNext() << '\n';
    line.ServeNextClient();
    std::cout << "Waiting clients: " << line.GetTotalWaitingClients() << '\n';
}
