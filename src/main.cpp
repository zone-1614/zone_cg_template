#include <iostream>
#include <pmp/visualization/MeshViewer.h>
#include <imgui.h>
#include <fstream>

#include <zone_cg_template/config.h>

class MeshViewer : public pmp::MeshViewer {
public: 
    MeshViewer(const char* title, int width, int height);
protected:
    virtual void process_imgui();

private:
    int subdivision_times = 0;
    int subdivision_type = 1;
};

int main() {
    MeshViewer window("zone_cg_template", 1500, 800);
    std::string filename = std::string(model_path) + "Bunny_head.obj";
    window.load_mesh(filename.c_str());
    window.run();
}

MeshViewer::MeshViewer(const char* title, int width, int height)
    : pmp::MeshViewer(title, width, height) { }

void MeshViewer::process_imgui() {
    pmp::MeshViewer::process_imgui();
    ImGui::Spacing();
    if (ImGui::CollapsingHeader("model", ImGuiTreeNodeFlags_DefaultOpen)) {
        const char* models[] = { "Balls", "Bunny_head", "Cat_head", "David328" };
        static int item_current_idx = 0;
        const char* combo_preview_value = models[item_current_idx];
        if (ImGui::BeginCombo("combo 1", combo_preview_value))
        {
            for (int n = 0; n < IM_ARRAYSIZE(models); n++)
            {
                const bool is_selected = (item_current_idx == n);
                if (ImGui::Selectable(models[n], is_selected)) {
                    std::cout << "choose" << std::endl;
                    item_current_idx = n;
                }

                if (is_selected)
                    ImGui::SetItemDefaultFocus();
            }
            ImGui::EndCombo();
        }
        // if (ImGui::Button("select")) {
        //     // do something
        // }
    }

    ImGui::Spacing();
    if (ImGui::CollapsingHeader("Subdivision", ImGuiTreeNodeFlags_DefaultOpen)) {
        ImGui::RadioButton("loop subdivision", &subdivision_type, 0);
        ImGui::RadioButton("catmull clark subdivision", &subdivision_type, 1);
        ImGui::SliderInt("subdivision times", &subdivision_times, 0, 5);
        if (ImGui::Button("execute")) {
            // subdivision
        }
    }

    ImGui::Spacing();
    if (ImGui::CollapsingHeader("Save as", ImGuiTreeNodeFlags_DefaultOpen)) {
        static char filename[128] = "save.obj";
        ImGui::InputText("filename", filename, IM_ARRAYSIZE(filename));
        if (ImGui::Button("save")) {
            // save mesh to file
        }
    }
}