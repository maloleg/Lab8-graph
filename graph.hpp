#pragma once
#include <iostream>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <algorithm>

template <typename T>
class Graph{
private:
    std::unordered_map<T, std::pair<std::pair<T, uint_fast64_t>, std::unordered_map<T, uint_fast64_t>>> Gr;

public:

    void Adjacency_matrix_print (std::string Filename, uint_fast64_t maxV){
        std::ofstream o;
        o.open(Filename);
        //std::cout << Gr.size();
        for (int i = 1; i <= maxV; i++){
            for (int j = 1; j <= maxV; j++){
                o << Gr[i].second[j];
                //std::cout << Gr[i].second[j] << "(" << i << ";" << j << ")";
                if (j != Gr.size()) o << " ";
            }
            if (i != Gr.size()) o << '\n';
            //std::cout << "\n";
        }
        o.close();
    }

    void SetEdges(uint_fast64_t First_Vertex, uint_fast64_t Second_Vertex, bool Direction){
        if (Direction){
            Gr[First_Vertex].second[Second_Vertex] += 1;
            Gr[First_Vertex].first.second += 1;
            //std::cout << "\n" << First_Vertex << ";" << Second_Vertex << " Setted\n";
        }
        else{
            Gr[First_Vertex].second[Second_Vertex] += 1;
            Gr[First_Vertex].first.second += 1;
            Gr[Second_Vertex].second[First_Vertex] += 1;
            Gr[Second_Vertex].first.second += 1;
            //std::cout << "\n" << First_Vertex << ";" << Second_Vertex << " Setted: "<< Gr[First_Vertex].first.second << "";
            //std::cout << "\n" << Second_Vertex << ";" << First_Vertex << " Setted: "<< Gr[Second_Vertex].first.second << "\n";

//            std::cout << "\n" << First_Vertex << " Setted: "<< Gr[First_Vertex].first.second << "";
//            std::cout << "\n" << Second_Vertex << " Setted: "<< Gr[Second_Vertex].first.second << "\n";
        }
    }

    void Vertexes_degree(std::string Filename){
        std::ofstream o;
        std::vector<uint_fast64_t> temp;
        o.open(Filename);
        for (auto& i : Gr) {temp.push_back(i.first);}

        std::sort(temp.begin(), temp.end());

        for (auto& i : temp){
            o << i << " " << Gr[i].first.second<< "\n";
        }

        o.close();
    }


};

