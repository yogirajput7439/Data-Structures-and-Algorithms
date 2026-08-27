Code 
Queues Algorithm 
# What is Queues 
Queue is Used In algorithm 
Enqueues and Dequeues Two types of Queues 


#include <queue>
using namespace std;

queue<int> q;

q.push(10);
q.push(20);
q.push(30);

cout << q.front();  // 10

q.pop();            // 10 हट गया

cout << q.front();  // 20
Enqueues - Last in last out 
