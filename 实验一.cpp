#include <iostream>
using namespace std;
#define MAXSIZE 50
typedef int ElemType;
// 顺序表结构体
typedef struct {
	ElemType data[MAXSIZE];
	int length; // 当前有效元素个数
} SqList;
// ====================== 三、实验内容 ======================
// 1. 初始化
void InitList(SqList& L) {
	L.length = 0;
}
// 2. 创建顺序表
void CreateList(SqList& L, int n) {
	if (n < 1 || n > MAXSIZE) return;
	cout << "请输入" << n << "个元素：";
	for (int i = 0; i < n; i++) {
		cin >> L.data[i];
	}
	L.length = n;
}
// 3. 判断顺序表是否为空
bool IsEmpty(SqList L) {
	return L.length == 0;
}
// 4. 计算顺序表的长度
int ListLength(SqList L) {
	return L.length;
}
// 5. 输出顺序表的内容
void PrintList(SqList L) {
	if (IsEmpty(L)) {
		cout << "顺序表为空！" << endl;
		return;
	}
	for (int i = 0; i < L.length; i++) {
		cout << L.data[i] << " ";
	}
	cout << endl;
}
// 6. 获取顺序表位置为position的元素值
bool GetElem(SqList L, int pos, ElemType& e) {
	if (pos < 1 || pos > L.length)
		return false;
	e = L.data[pos - 1];
	return true;
}
// 7. 在顺序表中查找元素值为value的元素位置（顺序查找和二分查找）
// 顺序查找
int SeqSearch(SqList L, ElemType val) {
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == val)
			return i + 1; // 返回位序（从1开始）
	}
	return -1; // 没找到返回-1
}
// 二分查找（要求顺序表有序）
int BinarySearch(SqList L, ElemType val) {
	int low = 0, high = L.length - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (L.data[mid] == val)
			return mid + 1;
		else if (L.data[mid] < val)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}
// 8. 指定一个元素，在此元素之前插入一个新元素（输入position和x，实现插入）
bool ListInsert(SqList& L, int pos, ElemType x) {
	if (pos < 1 || pos > L.length + 1 || L.length >= MAXSIZE)
		return false;
	// 元素后移
	for (int i = L.length; i >= pos; i--) {
		L.data[i] = L.data[i - 1];
	}
	L.data[pos - 1] = x;
	L.length++;
	return true;
}
// 9. 删除指定位置position的元素
bool ListDeletePos(SqList& L, int pos) {
	if (pos < 1 || pos > L.length)
		return false;
	for (int i = pos; i < L.length; i++) {
		L.data[i - 1] = L.data[i];
	}
	L.length--;
	return true;
}
// 10. 删除指定元素值value（注意多个相同元素应当删除）
void ListDeleteValue(SqList& L, ElemType val) {
	int j = 0;
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] != val) {
			L.data[j++] = L.data[i];
		}
	}
	L.length = j;
}
// 主函数 测试菜单
int main() {
	SqList L;
	InitList(L);
	int op, n, pos, res;
	ElemType e, x, val;
	while (true) {
		cout << "\n=====顺序表菜单=====" << endl;
		cout << "1 创建顺序表\n2 判断空\n3 求长度\n4 输出\n5 按位置取元素\n6 顺序查找\n7 二分查找\n8 按位置插入\n9 按位置删除\n10 删除全部等值元素\n0 退出\n请选择：";
		cin >> op;
		switch (op) {
		case 1:
			cout << "输入创建元素个数："; cin >> n;
			CreateList(L, n); break;
		case 2:
			if (IsEmpty(L)) cout << "顺序表是空" << endl;
			else cout << "顺序表非空" << endl;
			break;
		case 3:
			cout << "顺序表长度：" << ListLength(L) << endl; break;
		case 4: PrintList(L); break;
		case 5:
			cout << "输入要获取的位置pos："; cin >> pos;
			if (GetElem(L, pos, e)) cout << "该位置元素=" << e << endl;
			else cout << "位置非法" << endl;
			break;
		case 6:
			cout << "查找值："; cin >> val;
			res = SeqSearch(L, val);
			if (res == -1) cout << "未找到" << endl;
			else cout << "顺序查找结果，位序=" << res << endl;
			break;
		case 7:
			cout << "二分查找值（表必须有序！）："; cin >> val;
			res = BinarySearch(L, val);
			if (res == -1) cout << "未找到" << endl;
			else cout << "二分查找位序=" << res << endl;
			break;
		case 8:
			cout << "插入位置pos、插入值x："; cin >> pos >> x;
			if (ListInsert(L, pos, x)) cout << "插入成功" << endl;
			else cout << "插入失败" << endl;
			break;
		case 9:
			cout << "删除位置pos："; cin >> pos;
			if (ListDeletePos(L, pos)) cout << "删除成功" << endl;
			else cout << "删除失败" << endl;
			break;
		case 10:
			cout << "删除所有等于的值："; cin >> val;
			ListDeleteValue(L, val);
			cout << "已删除全部等值元素" << endl;
			break;
		case 0: return 0;
		}
	}
	return 0;
}