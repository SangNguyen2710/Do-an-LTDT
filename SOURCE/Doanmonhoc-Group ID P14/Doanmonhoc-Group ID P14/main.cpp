#include "header.h"
#include "Euler.h"
#include "Hamilton.h"

int main()
{
	setlocale(LC_ALL, "en_US.UTF-8");
	SetConsoleOutputCP(CP_UTF8); 

	// Khởi tạo các danh sách đỉnh, cạnh và đồ thị
	std::vector<Vertex> danhsachdinh;
	std::vector<Edge> danhsachcanh;
	Graph graph;


	// Lấy path input từ user và ghi dữ liệu vào graph
	read_file(graph);
	Graph graph2 = graph;

	int dinhbatdau;
	printf("Nhap dinh bat dau: ");
	scanf_s("%d", &dinhbatdau);




	
	// Thuật toán Euler
	int kq = Eulerv2(graph, danhsachcanh, dinhbatdau);
	if (kq == 1 || kq == 2)
	{
		printf("Duong di Euler: \n");
		for (int i = 0; i < danhsachcanh.size(); i++)
		{
			printf("Canh %d - %d \n", danhsachcanh[i].start, danhsachcanh[i].end);
		}
	}
	else
	{
		printf("Khong co duong di Euler\n");
	}
	

	//Thuật toán hamilton
	std::vector<int> duongdi_hamilton;
	int kq_h = Hamilton(graph2, duongdi_hamilton, dinhbatdau);
	if (kq_h == 1 || kq_h == 2)
	{
		printf("Duong di Hamilton: \n");
		for (int i = 0; i < duongdi_hamilton.size(); i++)
			printf("%d ", duongdi_hamilton[i]);
	}
	else
		printf("Khong co duong di Hamilton\n");

	return 0;
}