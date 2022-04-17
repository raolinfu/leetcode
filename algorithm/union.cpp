#include <vector>
#include <iostream>
using namespace std;

class Union {
    private:
        size_t size_;
        size_t cnt;
        vector<int> parents;
        int find(int a);
    public:
        Union(size_t size);
        void unify(int a, int b);
        bool connected(int a, int b);
        int getCnt() { return cnt;};
};

Union::Union(size_t size) {
    size_ = size;
    cnt = size;
    parents = vector<int>(size);
    for (int i = 0; i < size_; i++)
        parents[i] = i;
}

int Union::find(int a) {
    while (a != parents[a])
        a = parents[a];
    return a;
}

void Union::unify(int a, int b) {
    int p1 = find(a);
    int p2 = find(b);
    if (p1 == p2)
        return;
    --cnt;
    parents[p1] = p2;
}

bool Union::connected(int a, int b) {
    int p1 = find(a);
    int p2 = find(b);

    return p1 == p2;
}
int main() {
    Union u(5);
    u.unify(1, 2);
    u.unify(1, 3);
    u.unify(2, 4);
    cout<< u.getCnt()<< endl;
    cout<< u.connected(1, 4)<< endl;
    cout<< u.connected(2, 3)<< endl;
    cout<< u.connected(1, 3)<< endl;
    cout<< u.connected(1, 0)<< endl;

    return 0;
}
