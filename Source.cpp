#include <iostream>
#include "MyDate.h"
#include "Calander.h"
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	Calander c1;
	c1.printC();

	MyDate c("C", 22, 12, 332);
	MyDate c8("C1", 18, 5, 4712);
	MyDate c2("C2", 12, 2, 2012);
	MyDate c3("C3", 2, 9, 1273);
	MyDate c4("C4", 4, 2, 8364);

	MyDate a;
	MyDate b("JNjj");
	b.setComment("hb");
	b.print();
	Calander w;
	Calander v(w);
	if (w.isFree(3))
		cout << "location 3 is free" << endl;
	cout << w.firstFree();
	cout << endl;
	w.setDate(0, c8);
	w.setDate(1, c8);
	w.setDate(2, c8);
	w.setDate(3, c8);
	w.setDate(4, c8);
	w.setDate(5, c8);
	w.setDate(6, c8);
	w.setDate(7, c8);
	w.setDate(8, c8);
	w.setDate(9, c8);
	w.setDate(10, c8);
	w.setDate(11, c8);
	w.setDate(12, c8);
	w.setDate(13, c8);
	w.setDate(14, c);
	w.setDate(15, c8);
	w.setDate(16, c8);
	w.setDate(17, c8);
	w.setDate(18, c8);
	w.setDate(19, c8);
	w.setDate(20, c8);
	w.setDate(21, c8);
	w.setDate(22, c8);
	w.setDate(23, c8);
	w.setDate(24, c8);
	w.setDate(25, c8);
	w.setDate(26, c8);
	w.setDate(27, c3);
	w.setDate(27, c3);
	w.setDate(28, c8);
	w.setDate(29, c3);
	cout << w.oldest();
	cout << endl;
	cout << w.datesNum();
	cout << endl;
	cout << w.firstFree();
	cout << endl;
	w.delete1(6);
	if (w.insert(c4))
		cout << "insert succeeded" << endl;
	w.deleteAll();
	cout << w.firstFree();
	cout << endl;
	if (w.isFree(6))
		cout << "location 6 is free" << endl;

	w.setDate(0, c8);
	w.setDate(1, c8);
	w.setDate(9, c8);
	w.setDate(12, c8);
	w.setDate(13, c8);
	w.setDate(14, c);
	w.setDate(15, c8);
	w.setDate(21, c8);
	w.setDate(22, c8);
	w.setDate(25, c8);
	w.setDate(26, c8);
	w.setDate(27, c3);
	w.setDate(27, c3);
	w.setDate(28, c8);
	w.setDate(29, c3);
	if (w.isFree(2))
		cout << "location 28 is free" << endl;
	cout << w.datesNum();
	cout << endl;
	cout << w.firstFree();
	cout << endl;

	b.init();
	MyDate d(b);
	MyDate o("omj", 2, 2, 3982);
	c.inc();
	MyDate q("omj", 28, 2, 3982);
	q.inc();

	MyDate n("omj", 30, 12, 3982);
	n.inc();
	MyDate e("omj", 31, 12, 3982);
	e.inc();

	MyDate r("omj", 31, 10, 3982);
	r.inc();

	MyDate t("omj", 30, 6, 3982);
	t.inc();

	MyDate s("omj", 31, 12, 82);
	s.inc();

	MyDate z("omj", 2, 2, 3982);
	z.inc();
	MyDate x("omj", 2, 2, 3982);

	x.inc();
	if (c.isBefore(b))
		cout << "c is before b";
}