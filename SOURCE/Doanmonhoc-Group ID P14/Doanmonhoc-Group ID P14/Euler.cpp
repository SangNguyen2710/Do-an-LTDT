#include "Euler.h"

bool is_bridge(Graph& graph, int dinhbatdau, int dinhnguon, std::vector<int>& danhsachdinh)
{
	Graph newgraph = graph;
	//Đánh dấu đỉnh nguồn và đỉnh bắt đầu là đã duyệt để tạm xóa ra khỏi danh sách cạnh
	int index_nguon = -1;
	int index_batdau = -1;
	for (int i = 0; i < newgraph.danhsachdinh[dinhnguon].dinhlienke.size(); i++)
	{
		if (newgraph.danhsachdinh[dinhnguon].dinhlienke[i] == dinhbatdau && graph.danhsachdinh[dinhnguon].available[i])
		{
			newgraph.danhsachdinh[dinhnguon].available[i] = false;
			index_nguon = i;
		}
	}

	for (int i = 0; i < newgraph.danhsachdinh[dinhbatdau].dinhlienke.size(); i++)
	{
		if (newgraph.danhsachdinh[dinhbatdau].dinhlienke[i] == dinhnguon && newgraph.danhsachdinh[dinhbatdau].available[i])
		{
			newgraph.danhsachdinh[dinhbatdau].available[i] = false;
			index_batdau = i;
		}
	}
	bool result = DFS(newgraph, dinhbatdau, dinhnguon, danhsachdinh);
	if (result)
	{
		newgraph.danhsachdinh[dinhnguon].available[index_nguon] = true;
		newgraph.danhsachdinh[dinhbatdau].available[index_batdau] = true;
		return false;
	}
	else
	{
		newgraph.danhsachdinh[dinhnguon].available[index_nguon] = true;
		newgraph.danhsachdinh[dinhbatdau].available[index_batdau] = true;
		return true;
	}
}

bool DFS(Graph& graph, int dinhbatdau, int dinhnguon, std::vector<int>& danhsachdinh)
{	

	for (int i = 0; i < graph.danhsachdinh[dinhbatdau].dinhlienke.size(); i++)
	{
		int nextvertex = graph.danhsachdinh[dinhbatdau].dinhlienke[i];
		
		if (nextvertex == dinhnguon && graph.danhsachdinh[dinhbatdau].available[i]) return true;

		if (graph.danhsachdinh[dinhbatdau].available[i])
		{
			int dinhcha = -1;
			graph.danhsachdinh[dinhbatdau].available[i] = false;
			// Đi đến đỉnh tiếp theo để set giá trị available từ đỉnh cha thành 
			for (int j = 0; j < graph.danhsachdinh[nextvertex].dinhlienke.size(); j++)
			{
				if ((graph.danhsachdinh[nextvertex].dinhlienke[j] == dinhbatdau) && graph.danhsachdinh[nextvertex].available[j])
				{
					graph.danhsachdinh[nextvertex].available[j] = false;
					dinhcha = j;
					break;
				}
			}
			bool result = DFS(graph, nextvertex, dinhnguon, danhsachdinh);
			if (!result)
			{
				//Nếu không tìm thấy đường đi trả về giá trị ban đầu
				if(i>=0)graph.danhsachdinh[dinhbatdau].available[i] = true;
				if(dinhcha >= 0)graph.danhsachdinh[nextvertex].available[dinhcha] = true;
			}
			else {
				if (i >= 0)graph.danhsachdinh[dinhbatdau].available[i] = true;
				if (dinhcha >= 0)graph.danhsachdinh[nextvertex].available[dinhcha] = true;
				return true;
			}
		}
	}
	return false;
}

int Eulerv2(Graph& graph, std::vector<Edge>& danhsachcanh, int dinhbatdau)
{
	int dinhhientai = dinhbatdau;
	std::vector<int>canhcau;
	std::vector<int>danhsachdinhdfs;
	for (int i = 0; i < graph.danhsachdinh[dinhbatdau].dinhlienke.size(); i++)
	{
		// Lấy index của đỉnh tiếp theo
		int next_vertex = graph.danhsachdinh[dinhbatdau].dinhlienke[i];
		// Kiểm tra nếu là cạnh cầu thì cho vào danh sách duyệt sau


		// Nếu không là cạnh cầu xét đỉnh cạnh mới từ đỉnh xuất phát tới đỉnh tiếp theo đã được đi qua hay chưa
		if (graph.danhsachdinh[dinhbatdau].available[i])
		{
			if (is_bridge(graph, next_vertex, dinhbatdau, danhsachdinhdfs))
			{
				canhcau.push_back(i);
				continue;
			}
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
			int result = Eulerv2(graph, danhsachcanh, next_vertex);
			if (result != 0) return result;

			//Backtrack set lại status để thử đường đi khác và xóa cạnh vừa duyệt ra khỏi danh sách cạnh
			graph.danhsachdinh[dinhbatdau].available[i] = true;
			graph.danhsachdinh[next_vertex].available[index_dinhcha] = true;
			danhsachcanh.pop_back();
		}
	}

	// Khi duyệt xong thì bắt đầu duyệt cạnh cầu

	// Sau khi duyệt xong các cạnh không phải là cạnh cầu, bắt đầu duyệt cạnh cầu
	for (int i : canhcau) {
		int next_vertex = graph.danhsachdinh[dinhbatdau].dinhlienke[i];

		// Nếu cạnh cầu đã được đi qua rồi thì bỏ qua
		if (!graph.danhsachdinh[dinhbatdau].available[i]) {
			continue;
		}

		// Đánh dấu cạnh là đã đi qua
		graph.danhsachdinh[dinhbatdau].available[i] = false;
		Edge edge(dinhbatdau, next_vertex);
		danhsachcanh.push_back(edge);

		// Đi đến đỉnh tiếp theo và đánh dấu cạnh ngược cũng đã đi qua
		int index_dinhcha = -1;
		for (int j = 0; j < graph.danhsachdinh[next_vertex].dinhlienke.size(); j++) {
			if (graph.danhsachdinh[next_vertex].dinhlienke[j] == dinhbatdau && graph.danhsachdinh[next_vertex].available[j]) {
				graph.danhsachdinh[next_vertex].available[j] = false;
				index_dinhcha = j;
				break;
			}
		}

		// Gọi đệ quy tiếp tục với đỉnh mới
		int result = Eulerv2(graph, danhsachcanh, next_vertex);
		if (result != 0) return result;

		// Backtrack, phục hồi lại trạng thái của cạnh để thử các đường khác
		graph.danhsachdinh[dinhbatdau].available[i] = true;
		graph.danhsachdinh[next_vertex].available[index_dinhcha] = true;
		danhsachcanh.pop_back();
	}

	//Nếu chạy xong mà danh sách cạnh  là 0 thì không có đường đi
	if (danhsachcanh.size() == 0) return 0;
	// Kiểm tra điều kiện của chu trình hoặc đường đi Euler
	int sizedanhsachcanh = danhsachcanh.size()-1;
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