#include "header.h"
#include "Euler.h"


void main()
{
	setlocale(LC_ALL, "en_US.UTF-8");
	SetConsoleOutputCP(CP_UTF8); 

	// Khởi tạo các danh sách đỉnh, cạnh và đồ thị
	std::vector<Vertex> danhsachdinh;
	std::vector<Edge> danhsachcanh;
	Graph graph;

	// Lấy path input từ user và ghi dữ liệu vào graph
	read_file(graph);

	int dinhbatdau;
	printf("Nhap dinh bat dau: ");
	scanf_s("%d", &dinhbatdau);
	int kq = Euler(graph, danhsachcanh, dinhbatdau);
	if (kq == 1 || kq == 2)
	{
		printf("Lo trinh la: \n");
		for (int i = 0; i < danhsachcanh.size(); i++)
		{
			printf("Canh %d - %d \n", danhsachcanh[i].start, danhsachcanh[i].end);
		}
	}
	else
	{
		printf("Khong co lo trinh\n");
	}
}