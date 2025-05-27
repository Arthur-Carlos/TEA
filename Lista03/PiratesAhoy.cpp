#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
const int MAX = 1024010;

enum OperationType
{
    NORMAL,
    SET,
    CLEAR,
    FLIP
};

struct Node
{
    int summa = 0;
    OperationType type = NORMAL;
};

vector<Node> segTree;
vector<int> a;

int applyFlip(OperationType type)
{
    switch (type)
    {
    case SET:
        return CLEAR;
    case CLEAR:
        return SET;
    case FLIP:
        return NORMAL;
    default:
        return FLIP;
    }
}

void build(const vector<int> &a, int vertex, int left, int right)
{
    segTree[vertex].type = NORMAL;
    if (left == right)
    {
        segTree[vertex].summa = a[left];
    }
    else
    {
        int mid = (left + right) / 2;
        build(a, 2 * vertex, left, mid);
        build(a, 2 * vertex + 1, mid + 1, right);
        segTree[vertex].summa = segTree[2 * vertex].summa + segTree[2 * vertex + 1].summa;
    }
}

void push(int vertex, int left, int mid, int right)
{
    auto &node = segTree[vertex];
    auto &leftChild = segTree[2 * vertex];
    auto &rightChild = segTree[2 * vertex + 1];

    if (node.type == SET)
    {
        leftChild.type = rightChild.type = SET;
        leftChild.summa = mid - left + 1;
        rightChild.summa = right - mid;
    }
    else if (node.type == CLEAR)
    {
        leftChild.type = rightChild.type = CLEAR;
        leftChild.summa = rightChild.summa = 0;
    }
    else if (node.type == FLIP)
    {
        leftChild.type = static_cast<OperationType>(applyFlip(leftChild.type));
        rightChild.type = static_cast<OperationType>(applyFlip(rightChild.type));

        leftChild.summa = mid - left + 1 - leftChild.summa;
        rightChild.summa = right - mid - rightChild.summa;
    }

    node.type = NORMAL;
}

void update(int vertex, int left, int right, int esquerda, int direita, OperationType op)
{
    if (esquerda > direita)
        return;
    if (left == esquerda && right == direita)
    {
        if (op == SET)
        {
            segTree[vertex].type = SET;
            segTree[vertex].summa = right - left + 1;
        }
        else if (op == CLEAR)
        {
            segTree[vertex].type = CLEAR;
            segTree[vertex].summa = 0;
        }
        else if (op == FLIP)
        {
            segTree[vertex].type = static_cast<OperationType>(applyFlip(segTree[vertex].type));
            segTree[vertex].summa = right - left + 1 - segTree[vertex].summa;
        }
        return;
    }

    int mid = (left + right) / 2;
    push(vertex, left, mid, right);

    update(2 * vertex, left, mid, esquerda, min(direita, mid), op);
    update(2 * vertex + 1, mid + 1, right, max(esquerda, mid + 1), direita, op);

    segTree[vertex].summa = segTree[2 * vertex].summa + segTree[2 * vertex + 1].summa;
}

int query(int vertex, int left, int right, int esquerda, int direita)
{
    if (esquerda > direita)
        return 0;
    if (left == esquerda && right == direita)
        return segTree[vertex].summa;

    int mid = (left + right) / 2;
    push(vertex, left, mid, right);

    return query(2 * vertex, left, mid, esquerda, min(direita, mid)) +
           query(2 * vertex + 1, mid + 1, right, max(esquerda, mid + 1), direita);
}

int main()
{
    ios::sync_with_stdio(false);
    int tests;
    cin >> tests;
    for (int cs = 1; cs <= tests; ++cs)
    {
        int m;
        cin >> m;

        a.clear();
        for (int i = 0; i < m; ++i)
        {
            int t;
            string s;
            cin >> t >> s;
            for (int k = 0; k < t; ++k)
                for (char c : s)
                    a.push_back(c - '0');
        }

        int n = a.size();
        segTree.assign(4 * n, Node());
        build(a, 1, 0, n - 1);

        cout << "Case " << cs << ":\n";

        int q;
        cin >> q;
        int qnum = 1;

        while (q--)
        {
            char ch;
            int esquerda, direita;
            cin >> ch >> esquerda >> direita;

            switch (ch)
            {
            case 'F':
                update(1, 0, n - 1, esquerda, direita, SET);
                break;
            case 'E':
                update(1, 0, n - 1, esquerda, direita, CLEAR);
                break;
            case 'I':
                update(1, 0, n - 1, esquerda, direita, FLIP);
                break;
            case 'S':
                cout << "Q" << qnum++ << ": " << query(1, 0, n - 1, esquerda, direita) << "\n";
                break;
            }
        }
    }

    return 0;
}