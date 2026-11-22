
#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq;
    int n, num;

    cout << "Enter number of elements: ";
    cin >> n;

    if (n < 3) {
        cout << "Enter at least 3 numbers.";
        return 0;
    }

    cout << "Enter numbers: ";

    for (int i = 0; i < n; i++) {
        cin >> num;
        pq.push(num);
    }

    cout << "Three largest numbers: ";

    for (int i = 0; i < 3; i++) {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}
