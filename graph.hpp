#pragma once
#include <iostream>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <algorithm>

#define DEFAULT_WEIGHT 1

template <typename T>
class Graph{
private:
    std::unordered_map<uint_fast64_t,
                    std::pair<uint_fast64_t,
                    std::unordered_map<uint_fast64_t,
                    std::unordered_map<T, uint_fast64_t>>>> Gr;

public:

    void Adjacency_matrix_print (std::string Filename, uint_fast64_t maxV, bool Weighted){
        std::ofstream o;
        o.open(Filename);
        //std::cout << Gr.size();
        if (Weighted){

        }
        else{
            //std::cout << "MaxV = " << maxV << "\n";

            for (int i = 1; i <= maxV; i++){
            for (int j = 1; j <= maxV; j++){
                o << Gr[i].second[j][(T) 1];
                if (j != maxV) o << " ";

                //std::cout << Gr[i].second[j][(T) 1] << "(" << i << ";" << j << ")";
                //if (j != maxV - 1) std::cout << " ";
            }
            if (i != maxV) o << "\n";
            //if (i != maxV) std::cout << "\n";
        }
        o.close();
        }
    }

    void Adjacency_matrix_print (std::string Filename, uint_fast64_t maxV){
        std::ofstream o;
        o.open(Filename);
        //std::cout << Gr.size();
            //std::cout << "MaxV = " << maxV << "\n";
        for (int i = 1; i <= maxV; i++){
            for (int j = 1; j <= maxV; j++){
                o << Gr[i].second[j][(T) DEFAULT_WEIGHT];
                if (j != maxV) o << " ";

                //std::cout << Gr[i].second[j][(T) 1] << "(" << i << ";" << j << ")";
                //if (j != maxV - 1) std::cout << " ";
            }
            if (i != maxV) o << "\n";
            //if (i != maxV) std::cout << "\n";
        }
        o.close();
    }

    void SetEdges(uint_fast64_t First_Vertex, uint_fast64_t Second_Vertex, T Weight, bool Direction){
        if (Direction){
            Gr[First_Vertex].second[Second_Vertex][Weight] += 1;
            Gr[First_Vertex].first += 1;
            //std::cout << "\n" << First_Vertex << ";" << Second_Vertex << " Setted\n";
        }
        else{
            Gr[First_Vertex].second[Second_Vertex][Weight] += 1;
            Gr[First_Vertex].first += 1;
            Gr[Second_Vertex].second[First_Vertex][Weight] += 1;
            Gr[Second_Vertex].first += 1;

            //std::cout << Gr[1].second[2][(T) 1] << "(" << 1 << ";" << 2 << ")";
            //std::cout << "\n" << First_Vertex << ";" << Second_Vertex << " Setted: "<< Gr[First_Vertex].first.second << "";
            //std::cout << "\n" << Second_Vertex << ";" << First_Vertex << " Setted: "<< Gr[Second_Vertex].first.second << "\n";

//            std::cout << "\n" << First_Vertex << " Setted: "<< Gr[First_Vertex].first.second << "";
//            std::cout << "\n" << Second_Vertex << " Setted: "<< Gr[Second_Vertex].first.second << "\n";
        }
    }

    void SetEdges(uint_fast64_t First_Vertex, uint_fast64_t Second_Vertex, bool Direction){
        if (Direction){
            Gr[First_Vertex].second[Second_Vertex][(T) DEFAULT_WEIGHT] += 1;
            Gr[First_Vertex].first += 1;
            //std::cout << "\n" << First_Vertex << ";" << Second_Vertex << " Setted\n";
        }
        else{
            Gr[First_Vertex].second[Second_Vertex][(T) DEFAULT_WEIGHT] += 1;
            Gr[First_Vertex].first += 1;
            Gr[Second_Vertex].second[First_Vertex][(T) DEFAULT_WEIGHT] += 1;
            Gr[Second_Vertex].first += 1;

            //std::cout << Gr[1].second[2][(T) 1] << "(" << 1 << ";" << 2 << ")";
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
            o << i << " " << Gr[i].first<< "\n";
        }

        o.close();
    }

    void Shortest_path(uint_fast64_t first, uint_fast64_t last, std::string Filename){

    }


};

