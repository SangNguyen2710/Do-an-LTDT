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

	Euler(graph, danhsachcanh, 9);
}