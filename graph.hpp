#pragma once
#include <iostream>
#include <unordered_map>
#include <fstream>

template <typename T>
class Graph{
private:
    std::unordered_map<T, std::pair<T, std::unordered_map<T, bool>>> Gr;

public:

    void Adjacency_matrix_print (std::string Filename){
        std::ofstream o;
        o.open(Filename);
        //std::cout << Gr.size();
        for (int i = 1; i <= Gr.size(); i++){
            for (int j = 1; j <= Gr.size(); j++){
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
            Gr[First_Vertex].second[Second_Vertex] = true;
            //std::cout << "\n" << First_Vertex << ";" << Second_Vertex << " Setted\n";
        }
        else{
            Gr[First_Vertex].second[Second_Vertex] = true;
            Gr[Second_Vertex].second[First_Vertex] = true;
            //std::cout << "\n" << First_Vertex << ";" << Second_Vertex << " Setted";
            //std::cout << "\n" << Second_Vertex << ";" << First_Vertex << " Setted\n";
        }
    }


};

