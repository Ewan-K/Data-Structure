#include <iostream>
#include <typeinfo>
using namespace std;

typedef class Node *List;
// Base
class Node
{
public:
    List Next;

public:
    Node(){};
    virtual ~Node(){};
    virtual void printData() const;     // 仅在派生类中定义
    virtual int tellType() const;       // 判断数据类型
    virtual void Output();              // 遍历链表输出
    virtual List FindKth(int K);        // 查找并指向第K个元素
    virtual List Insert(int K, List X); // 在第K个位置插入元素X（已初始化的对象）
    virtual List DeleteKth(int K);      // 删除第K个位置的元素
    virtual List Reverse();             // 逆置链表
    virtual List Merge(List L1);        // 合并链表，将this追加到L1后
    virtual List sortByType();          // 按值的类型排序（先INT，再DOUBLE，后CHAR）
    virtual List Destroy();             // 销毁链表
};
// Derived
template <class T>
class NodeS : public Node
{
private:
    T Data;

public:
    NodeS(T Data, List Next) : Data(Data)
    {
        this->Next = Next;
    };
    ~NodeS(){};
    void printData() const
    {
        cout << Data << endl;
    };
    int tellType() const
    {
        if (typeid(Data) == typeid(int))
            return 1;
        else if (typeid(Data) == typeid(double))
            return 2;
        else
            return 3;
    };
    void Output();              // 遍历链表输出
    List FindKth(int K);        // 查找并指向第K个元素
    List Insert(int K, List X); // 在第K个位置插入元素X（已初始化的对象）
    List DeleteKth(int K);      // 删除第K个位置的元素
    List Reverse();             // 逆置链表
    List Merge(List L1);        // 合并链表，将this追加到L1后
    List sortByType();          // 按值的类型排序（先INT，再DOUBLE，后CHAR）
    List Destroy();             // 销毁链表
};

int main()
{
    // 建立链表
    NodeS<int> L1(-1, nullptr); // 必须用一个对象节点做头结点
    NodeS<int> L2(-2, nullptr);
    List PtrL1 = &L1, PtrL2 = &L2;
    // 插入
    NodeS<int> I1(1, nullptr);
    NodeS<int> I2(2, nullptr);
    NodeS<double> D1(2020.11, nullptr);
    NodeS<double> D2(2020.22, nullptr);
    NodeS<char> C1('a', nullptr);
    NodeS<char> C2('b', nullptr);

    PtrL1 = PtrL1->Insert(1, &I1);
    PtrL1 = PtrL1->Insert(2, &I2);
    PtrL1 = PtrL1->Insert(3, &D1);
    PtrL2 = PtrL2->Insert(1, &C1);
    PtrL2 = PtrL2->Insert(2, &C2);
    PtrL2 = PtrL2->Insert(3, &D2);
    //输出
    cout << "插入后的结果：" << endl;
    cout << "PtrL1中元素：" << endl;
    PtrL1->Output();
    cout << "PtrL2中元素：" << endl;
    PtrL2->Output();

    cout << endl;

    // //删除
    // PtrL1 = PtrL1->DeleteKth(2);
    // PtrL2 = PtrL2->DeleteKth(2);
    // //输出
    // cout << "删除后的结果：" << endl;
    // cout << "PtrL1中元素：" << endl;
    // PtrL1->Output();
    // cout << "PtrL2中元素：" << endl;
    // PtrL2->Output();

    // cout << endl;

    // //逆置
    // PtrL1 = PtrL1->Reverse();
    // PtrL2 = PtrL2->Reverse();
    // //输出
    // cout << "逆置后的结果：" << endl;
    // cout << "PtrL1中元素：" << endl;
    // PtrL1->Output();
    // cout << "PtrL2中元素：" << endl;
    // PtrL2->Output();

    // cout << endl;

    // 合并
    PtrL1 = PtrL1->Merge(PtrL2);
    // 输出
    cout << "合并后的结果：" << endl;
    cout << "PtrL1中元素：" << endl;
    PtrL1->Output();
    // PtrL2->Output(); // 这里用PtrL2输出结果相同
    cout << endl;

    // 排序
    PtrL1 = PtrL1->sortByType();
    // 输出
    cout << "排序后的结果：" << endl;
    cout << "PtrL1中元素：" << endl;
    PtrL1->Output();

    cout << endl;

    // 销毁
    PtrL1 = PtrL1->Destroy();
    // 输出
    cout << "销毁后的结果：" << endl;
    cout << "PtrL1中元素：" << endl;
    PtrL1->Output();

    getchar();
    getchar();
}

template <class T>
void NodeS<T>::Output()
{
    List p = this;
    if (!p)
    {
        cout << "链表为空！" << endl;
        return;
    }
    else
    {
        while (p)
        {
            cout << "该节点值为: ";
            p->printData();
            cout << endl;
            p = p->Next;
        }
        return;
    }
}

template <class T>
List NodeS<T>::FindKth(int K)
{
    List L = this;
    int i = 1;
    while (L && i < K)
    {
        L = L->Next;
        i++;
    }
    if (i == K)
        return L;
    else
    {
        cout << "K位置无法查" << endl;
        return nullptr;
    }
}

template <class T>
List NodeS<T>::Insert(int K, List X)
{
    List p, l;
    if (K == 1)
    {
        p = X;
        p->Next = this;
        return p;
    }
    l = FindKth(K - 1);
    if (l)
    {
        p = X;
        p->Next = l->Next;
        l->Next = p;
        return this;
    }
    else
    {
        cout << "K位置无法插入！" << endl;
        return nullptr;
    }
}

template <class T>
List NodeS<T>::DeleteKth(int K)
{
    List p, l;
    if (K == 1)
    {
        p = this;
        p = p->Next;
        // delete p; // 不能在一个对象内部把自己删除
        return p;
    }
    l = FindKth(K - 1);
    if (l && l->Next)
    {
        p = l->Next;
        l->Next = p->Next;
        // delete p; // 跳过待删除而后续还要用到的对象
        return this;
    }
    else
    {
        cout << "位置K无法删除" << endl;
        return nullptr;
    }
}

template <class T>
List NodeS<T>::Reverse()
{
    List pPre, pCur, pNext;
    pPre = this;
    pCur = pPre->Next;
    pNext = nullptr;
    while (pCur)
    {
        pNext = pCur->Next;
        pCur->Next = pPre;
        pPre = pCur;
        pCur = pNext;
    }
    this->Next = nullptr;
    return pPre;
}

template <class T>
List NodeS<T>::Merge(List L1)
{
    List L = L1;
    while (L->Next)
        L = L->Next;
    L->Next = this;
    return L1;
}

template <class T>
List NodeS<T>::sortByType()
{
    List p = this, pIH, pIE, pDH, pDE, pCH, pCE;
    pIH = pIE = nullptr;
    pDH = pDE = nullptr;
    pCH = pCE = nullptr;
    while (p)
    {
        if (p->tellType() == 1)
        {
            if (!pIH)
            {
                pIH = pIE = p;
            }
            else
            {
                pIE->Next = p;
                pIE = p;
            }
        }
        else if (p->tellType() == 2)
        {
            if (!pDH)
            {
                pDH = pDE = p;
            }
            else
            {
                pDE->Next = p;
                pDE = p;
            }
        }
        else
        {
            if (!pCH)
            {
                pCH = pCE = p;
            }
            else
            {
                pCE->Next = p;
                pCE = p;
            }
        }
        p = p->Next;
    }
    pIE->Next = pDH;
    pDE->Next = pCH;
    pCE->Next = nullptr;
    return pIH;
}

template <class T>
List NodeS<T>::Destroy()
{
    this->Next = nullptr;
    return this;
}