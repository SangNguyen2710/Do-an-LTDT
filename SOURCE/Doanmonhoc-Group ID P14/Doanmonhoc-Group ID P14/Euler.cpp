#include "Euler.h"
int Euler(Graph &graph, std::vector<Edge> &danhsachcanh, int dinhbatdau)
{
	int dinhhientai = dinhbatdau;
	for (int i = 0; i < graph.danhsachdinh[dinhbatdau].dinhlienke.size(); i++)
	{
		// Lấy index của đỉnh tiếp theo
		int next_vertex = graph.danhsachdinh[dinhbatdau].dinhlienke[i];
		
		// Xét đỉnh cạnh mới từ đỉnh xuất phát tới đỉnh tiếp theo đã được đi qua hay chưa
		if (graph.danhsachdinh[dinhbatdau].available[i])
		{
			// Set giá trị tại index i là false nghĩa là cạnh đã được đi qua và thêm giá trị vào edge
			graph.danhsachdinh[dinhbatdau].available[i] = false;
			Edge edge(dinhbatdau, next_vertex);
			danhsachcanh.push_back(edge);

			// Đi đến đỉnh tiếp theo để set giá trị available từ đỉnh cha thành 
			int index_dinhcha = -1;
			for (int j = 0; j < graph.danhsachdinh[next_vertex].dinhlienke.size(); j++)
			{
				if ((graph.danhsachdinh[next_vertex].dinhlienke[j] == dinhbatdau) && (graph.danhsachdinh[next_vertex].available[j] == true))
				{
					graph.danhsachdinh[next_vertex].available[j] = false;
					index_dinhcha = j;
					break;
				}
			}
			int result = Euler(graph, danhsachcanh, next_vertex);
			if (result != 0) return result;

			//Backtrack set lại status để thử đường đi khác và xóa cạnh vừa duyệt ra khỏi danh sách cạnh
			graph.danhsachdinh[dinhbatdau].available[i] = true;
			graph.danhsachdinh[next_vertex].available[index_dinhcha] = true;
			danhsachcanh.pop_back();
		}
	}

	// Kiểm tra điều kiện của chu trình hoặc đường đi Euler
	int sizedanhsachcanh = danhsachcanh.size() - 1;
	int dinhcuoi = danhsachcanh[sizedanhsachcanh].end;
	
	// Tính tổng số bậc
	int tongsobac = 0;
	for (int i = 0; i < graph.danhsachdinh.size(); i++)
	{
		tongsobac += graph.danhsachdinh[i].level;
	}

	// Return giá trị

	if (danhsachcanh.size() != (tongsobac / 2)) return 0; // Nếu số cạnh không bằng tổng số bậc chia 2, không có đường đi hay chi trinh Eul
	if (dinhbatdau == dinhcuoi) return 2;
	if (dinhbatdau != dinhcuoi) return 1;


}