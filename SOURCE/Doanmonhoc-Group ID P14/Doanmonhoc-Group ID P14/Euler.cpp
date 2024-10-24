#include "Euler.h"
int Euler(Graph &graph, std::vector<Edge> &danhsachcanh, int dinhbatdau)
{
	int dinhhientai = dinhbatdau;
	bool diduoctiep = false;
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
			for (int j = 0; j < graph.danhsachdinh[next_vertex].dinhlienke.size(); j++)
			{
				if ((graph.danhsachdinh[next_vertex].dinhlienke[j] == dinhbatdau) && (graph.danhsachdinh[next_vertex].available[j] == true))
				{
					graph.danhsachdinh[next_vertex].available[j] = false;
					break;
				}
			}
			diduoctiep = true;
			return Euler(graph, danhsachcanh, next_vertex);
		}
	}
	if (diduoctiep = false) return 0;
	int sizedanhsachcanh = danhsachcanh.size() - 1;
	int dinhcuoi = danhsachcanh[sizedanhsachcanh].end;
	
	// Tính tổng số bậc
	int tongsobac = 0;
	for (int i = 0; i < graph.danhsachdinh.size(); i++)
	{
		tongsobac += graph.danhsachdinh[i].level;
	}

	// Return giá trị

	if (danhsachcanh.size() != (tongsobac / 2)) return 0;
	if (dinhbatdau == dinhcuoi) return 2;
	if (dinhbatdau != dinhcuoi) return 1;


}