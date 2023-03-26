#include <iostream>
#include <pmp/visualization/MeshViewer.h>

int main() {
    pmp::MeshViewer window("zone_cg_template", 800, 600);
    window.run();
}