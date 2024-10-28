#pragma once
#include "header.h"


bool is_bridge(Graph& graph, int dinhbatdau, int dinhnguon, std::vector<int>& danhsachdinh);

bool DFS(Graph& graph, int dinhbatdau, int dinhnguon, std::vector<int> &danhsachdinh);

int Eulerv2(Graph& graph, std::vector<Edge>& danhsachcanh, int dinhbatdau);


