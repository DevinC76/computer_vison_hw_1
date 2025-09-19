// Program 1 - HW2
// Author: <Devin Chen>

#include <iostream>
#include <string>

#include "image.h"
using namespace ComputerVisionProjects;

int main(int argc, char **argv){
  
  if (argc != 4) {
    std::cout << "Usage: " <<
      argv[0] << " {input_image_name} {threshold} {output_image_name}" << std::endl;
    return 0;
  }
  const std::string input_file(argv[1]);
  const int threshold = std::stoi(argv[2]);
  const std::string output_file(argv[3]);

  Image image;
  if (!ReadImage(input_file, &image)) {
    std::cout <<"Can't open file " << input_file << std::endl;
    return 0;
  }  

  for(int i =0; i < image.num_rows(); ++i){
    for(int j =0; j <image.num_columns(); ++j){
        if(image.GetPixel(i,j) < threshold){
            image.SetPixel(i,j,0);
        }
        else{
            image.SetPixel(i,j,255);
        }
    }   
  }
  
  if (!WriteImage(output_file, image)){
    std::cout << "Can't write to file " << output_file << std::endl;
    return 0;
  }

  std::cout << "Running p1 " << input_file << " " 
            << threshold << " " << output_file << std::endl;
}
