#define IMGUI_DEFINE_MATH_OPERATORS

#include "gui/gui.hpp"

// elements ui
//const char* player_esp_box[] = { ("None"), ("2D"), ("3D") };
//const char* player_esp_health_type[] = { ("HP-Bar Right"), ("HP-Bar Top"), ("Percent"), ("Value") };
//const char* visual_font_type[] = { ("Text"), ("Icon") };

void Gui::create_styles()
{
	auto& style = ImGui::GetStyle();
	style.WindowPadding = { 0.f, 0.f };
	style.PopupRounding = 2.f;
	style.FramePadding = { 8.f, 4.f };
	style.ItemSpacing = { 10.f, 8.f };
	style.ItemInnerSpacing = { 6.f, 6.f };
	style.TouchExtraPadding = { 0.f, 0.f };
	style.IndentSpacing = 21.f;
	style.ScrollbarSize = 2.f;
	style.GrabMinSize = 1.f;
	style.WindowBorderSize = 0.f;
	style.ChildBorderSize = 0.f;
	style.PopupBorderSize = 0.f;
	style.FrameBorderSize = 0.f;
	style.TabBorderSize = 0.f;
	style.WindowRounding = 4.f;
	style.ChildRounding = 4.f;
	style.FrameRounding = 4.f;
	style.ScrollbarRounding = 0.f;
	style.GrabRounding = 0.f;
	style.TabRounding = 0.f;
	style.WindowTitleAlign = { 0.5f, 0.5f };
	style.ButtonTextAlign = { 0.5f, 0.5f };
	style.DisplaySafeAreaPadding = { 3.f, 3.f };

	style.Alpha = 1;

	ImGui::GetStyle().Colors[ImGuiCol_MainColorAccent] = ImVec4(71 / 255.f, 102 / 255.f, 255 / 255.f, 1.f);
	ImGui::GetStyle().Colors[ImGuiCol_Button] = ImVec4(71 / 255.f, 102 / 255.f, 255 / 255.f, 1.f);
	ImGui::GetStyle().Colors[ImGuiCol_ButtonHovered] = ImVec4(107 / 255.f, 132 / 255.f, 255 / 255.f, 1.f);
	ImGui::GetStyle().Colors[ImGuiCol_ButtonActive] = ImVec4(68 / 255.f, 92 / 255.f, 212 / 255.f, 1.f);

	if (this->theme) {
		ImGui::GetStyle().Colors[ImGuiCol_Text] = ImVec4(20 / 255.f, 20 / 255.f, 20 / 255.f, 0.8f);

		ImGui::GetStyle().Colors[ImGuiCol_Header] = ImVec4(195 / 255.f, 195 / 255.f, 195 / 255.f, 0.8f);
		ImGui::GetStyle().Colors[ImGuiCol_HeaderActive] = ImVec4(195 / 255.f, 195 / 255.f, 195 / 255.f, 0.8f);
		ImGui::GetStyle().Colors[ImGuiCol_HeaderHovered] = ImVec4(210 / 255.f, 210 / 255.f, 210 / 255.f, 0.4f);
		ImGui::GetStyle().Colors[ImGuiCol_WindowBg] = ImVec4(230 / 255.f, 230 / 255.f, 230 / 255.f, 1.f);

		ImGui::GetStyle().Colors[ImGuiCol_FrameBg] = ImVec4(160 / 255.f, 160 / 255.f, 160 / 255.f, 1.f);
		ImGui::GetStyle().Colors[ImGuiCol_FrameBgHovered] = ImVec4(165 / 255.f, 165 / 255.f, 165 / 255.f, 1.f);
		ImGui::GetStyle().Colors[ImGuiCol_FrameBgActive] = ImVec4(155 / 255.f, 155 / 255.f, 155 / 255.f, 1.f);

		ImGui::GetStyle().Colors[ImGuiCol_ProfileCornerBackground] = ImVec4(185 / 255.f, 185 / 255.f, 185 / 255.f, 1.f);
		ImGui::GetStyle().Colors[ImGuiCol_SubtabActiveBackground] = ImVec4(185 / 255.f, 185 / 255.f, 185 / 255.f, 1.f);
		ImGui::GetStyle().Colors[ImGuiCol_SubtabZoneBackground] = ImVec4(205 / 255.f, 205 / 255.f, 205 / 255.f, 1.f);

		ImGui::GetStyle().Colors[ImGuiCol_ChildBg] = ImVec4(205 / 255.f, 205 / 255.f, 205 / 255.f, 1.f);
		ImGui::GetStyle().Colors[ImGuiCol_NetworkingItemBg] = ImVec4(220 / 255.f, 220 / 255.f, 220 / 255.f, 1.f);
		ImGui::GetStyle().Colors[ImGuiCol_ComboBg] = ImVec4(190 / 255.f, 190 / 255.f, 190 / 255.f, 1.f);

		ImGui::GetStyle().Colors[ImGuiCol_PopupBg] = ImVec4(150 / 255.f, 150 / 255.f, 150 / 255.f, 1.f);
	}
	else {
		ImGui::GetStyle().Colors[ImGuiCol_Text] = ImVec4(240 / 255.f, 240 / 255.f, 240 / 255.f, 0.8f);

		ImGui::GetStyle().Colors[ImGuiCol_Header] = ImVec4(60 / 255.f, 60 / 255.f, 60 / 255.f, 0.8f);
		ImGui::GetStyle().Colors[ImGuiCol_HeaderActive] = ImVec4(60 / 255.f, 60 / 255.f, 60 / 255.f, 0.8f);
		ImGui::GetStyle().Colors[ImGuiCol_HeaderHovered] = ImVec4(45 / 255.f, 45 / 255.f, 45 / 255.f, 0.4f);
		ImGui::GetStyle().Colors[ImGuiCol_WindowBg] = ImVec4(25 / 255.f, 25 / 255.f, 25 / 255.f, 1.f);

		ImGui::GetStyle().Colors[ImGuiCol_FrameBg] = ImVec4(95 / 255.f, 95 / 255.f, 95 / 255.f, 1.f);
		ImGui::GetStyle().Colors[ImGuiCol_FrameBgHovered] = ImVec4(90 / 255.f, 90 / 255.f, 90 / 255.f, 1.f);
		ImGui::GetStyle().Colors[ImGuiCol_FrameBgActive] = ImVec4(100 / 255.f, 100 / 255.f, 100 / 255.f, 1.f);

		ImGui::GetStyle().Colors[ImGuiCol_ProfileCornerBackground] = ImVec4(70 / 255.f, 70 / 255.f, 70 / 255.f, 1.f);
		ImGui::GetStyle().Colors[ImGuiCol_SubtabActiveBackground] = ImVec4(70 / 255.f, 70 / 255.f, 70 / 255.f, 1.f);
		ImGui::GetStyle().Colors[ImGuiCol_SubtabZoneBackground] = ImVec4(50 / 255.f, 50 / 255.f, 50 / 255.f, 1.f);

		ImGui::GetStyle().Colors[ImGuiCol_ChildBg] = ImVec4(50 / 255.f, 50 / 255.f, 50 / 255.f, 1.f);
		ImGui::GetStyle().Colors[ImGuiCol_NetworkingItemBg] = ImVec4(35 / 255.f, 35 / 255.f, 35 / 255.f, 1.f);
		ImGui::GetStyle().Colors[ImGuiCol_ComboBg] = ImVec4(60 / 255.f, 60 / 255.f, 60 / 255.f, 1.f);
		ImGui::GetStyle().Colors[ImGuiCol_PopupBg] = ImVec4(60 / 255.f, 60 / 255.f, 60 / 255.f, 1.f);

	}
}

void Gui::create_decorations() {
	auto size = ImGui::GetWindowSize();

	time_t rawtime;
	struct tm* timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	const char* time_c = asctime(timeinfo);

	/*
	@topbar
	*/
	this->draw_list->AddRectFilled(this->window_position + ImVec2(size.x - 195, 0), this->window_position + ImVec2(size.x, 39), ImGui::GetColorU32(ImGuiCol_ProfileCornerBackground), 4, ImDrawCornerFlags_TopRight);
	this->draw_list->AddCircleFilled(this->window_position + ImVec2(size.x - 170, 20 /*18*/), 13, ImColor(35, 35, 35), 32);
	this->draw_list->AddText(this->window_position + ImVec2(size.x - 150, 19 - ImGui::CalcTextSize("Administrator", NULL, false).y / 2), ImGui::GetColorU32(ImGuiCol_Text), "Administrator", nullptr);
	this->draw_list->AddRectFilled(this->window_position + ImVec2(0, 39), window_position + ImVec2(size.x, 78), ImGui::GetColorU32(ImGuiCol_SubtabZoneBackground));


	ImColor close_clr = ImGui::GetColorU32(ImGuiCol_Text);
	ImGui::SetCursorPos(ImVec2(size.x - 39, 0));
	if (ImGui::InvisibleButton("##unhook", { 39, 39 })) {
		this->bMenuOpen = !this->bMenuOpen;//g::unhook = true;
		//natives::ScreenBlur(350, Xanoty.menuOpen);
		std::async(std::launch::async, [] { Beep(100, 60); });
	}

	if (ImGui::IsItemHovered())
		ImGui::SetMouseCursor(7),
		close_clr = ImGui::GetColorU32(ImGuiCol_Text);
	else
		close_clr = ImGui::GetColorU32(ImGuiCol_TextDisabled);

	this->draw_list->AddText(this->window_position + ImVec2(size.x - 25, 13), close_clr, (const char*)ICON_FA_TIMES);


	ImColor close_clr2 = ImGui::GetColorU32(ImGuiCol_Text);
	ImGui::SetCursorPos(ImVec2(size.x - 78, 0));
	if (ImGui::InvisibleButton("##changetheme", { 39, 39 }))
	{
		theme = !theme;
		create_styles();
	}

	if (ImGui::IsItemHovered())
		ImGui::SetMouseCursor(7),
		close_clr2 = ImGui::GetColorU32(ImGuiCol_Text);
	else
		close_clr2 = ImGui::GetColorU32(ImGuiCol_TextDisabled);

	this->draw_list->AddText(this->window_position + ImVec2(size.x - 25 - 39, 13), close_clr2, (const char*)ICON_FA_MOON);

	/*
	@ logotype
	*/
	c_menu_elements::Instance().draw_logo(this->window_position + ImVec2(15, 10), 23, ImGui::GetColorU32(ImGuiCol_MainColorAccent), ICON_FA_FISH);
	/*
	@ bottombar
	*/
	this->draw_list->AddRectFilled(this->window_position + ImVec2(0, size.y - 20), this->window_position + size, ImGui::GetColorU32(ImGuiCol_SubtabZoneBackground), 4, 12);
	this->draw_list->AddLine(this->window_position + ImVec2(0, size.y - 21), this->window_position + ImVec2(size.x, size.y - 21), ImGui::GetColorU32(ImGuiCol_SubtabActiveBackground));
	this->draw_list->AddCircleFilled(this->window_position + ImVec2(15, size.y - 10), 3, ImGui::GetColorU32(ImLerp(ImVec4(0.24f, 0.74f, 0.3f, 1.0f), ImVec4(0.34f, 0.45f, 0.35f, 1.0f), 0)));

	//auto text = Xanoty.running ? (const char*)((uintptr_t)GetModuleHandleA("altv-client.dll") + 0xCDD020) : "Disconnected";

	this->draw_list->AddText(this->window_position + ImVec2(25, size.y - ImGui::CalcTextSize("Connected", NULL, false).y / 2 - 11), ImGui::GetColorU32(ImGuiCol_Text), "Connected");
	this->draw_list->AddText(this->window_position + ImVec2(size.x - ImGui::CalcTextSize("nemo:V Multiplayer v0.1", NULL, false).x - 10, size.y - ImGui::CalcTextSize("nemo:V Multiplayer v0.1", NULL, false).y / 2 - 11), ImGui::GetColorU32(ImGuiCol_Text), "nemo:V Multiplayer v0.1");
	this->draw_list->AddText(this->window_position + ImVec2(size.x / 2 - ImGui::CalcTextSize(time_c, NULL, false).x / 2, size.y - ImGui::CalcTextSize(time_c, NULL, false).y / 2 - 11), ImGui::GetColorU32(ImGuiCol_Text), time_c);
}

void Gui::create_tabs()
{
	const char* tabs[8] = { "Home", "Visuals", "Aiming", "Miscellaneous",  "Configuration",  "Executor", "Admin" };

	ImGui::SetCursorPos({ 50, 0 });
	ImGui::BeginGroup();
	for (auto i = 0; i < 7; i++) {
		c_menu_elements::Instance().tab(tabs[i], &this->window_tab, i);

		if (i != 6)
			ImGui::SameLine();
	}
	ImGui::EndGroup();

	ImGui::SetCursorPos({ 0, 39 });
	ImGui::BeginChild("##subtab", ImVec2(750, 39));
	{
		switch (this->window_tab)
		{
		case 0:
			/*c_menu_elements::Instance().subtab(_xor_("Welcome").c_str(), (const char*)ICON_FA_HOME, &this->window_subtab_home, 0);
			*/break;
		case 1:
			/*c_menu_elements::Instance().subtab(_xor_("Player ESP").c_str(), (const char*)ICON_FA_WALKING, &this->window_subtab_visuals, 0);
			imsl;
			c_menu_elements::Instance().subtab(_xor_("Vehicle ESP").c_str(), (const char*)ICON_FA_CAR, &this->window_subtab_visuals, 1);
			*/break;
		case 2:
			/*c_menu_elements::Instance().subtab(_xor_("Aimbot").c_str(), (const char*)ICON_FA_CROSSHAIRS, &this->window_subtab_aiming, 0);
			imsl;
			c_menu_elements::Instance().subtab(_xor_("Legit-Aim").c_str(), (const char*)ICON_FA_SHIELD_CROSS, &this->window_subtab_aiming, 1);
			imsl;
			c_menu_elements::Instance().subtab(_xor_("Aim-Correction").c_str(), (const char*)ICON_FA_CHART_LINE, &this->window_subtab_aiming, 2);
			imsl;
			c_menu_elements::Instance().subtab(_xor_("Silent-Aim").c_str(), (const char*)ICON_FA_RADIATION_ALT, &this->window_subtab_aiming, 3);
			*/break;
		case 3:
			/*c_menu_elements::Instance().subtab(_xor_("Main").c_str(), (const char*)ICON_FA_USERS, &this->window_subtab_misc, 0);
			imsl;
			c_menu_elements::Instance().subtab(_xor_("Player list").c_str(), (const char*)ICON_FA_USERS, &this->window_subtab_misc, 1);
			imsl;
			c_menu_elements::Instance().subtab(_xor_("Chams").c_str(), (const char*)ICON_FA_ADJUST, &this->window_subtab_misc, 2);
			imsl;
			c_menu_elements::Instance().subtab(_xor_("Glow").c_str(), (const char*)ICON_FA_USER, &this->window_subtab_misc, 3);
			imsl;
			c_menu_elements::Instance().subtab(_xor_("Spoofer").c_str(), (const char*)ICON_FA_USER, &this->window_subtab_misc, 4);
			*/break;
		case 4:
			/*c_menu_elements::Instance().subtab(_xor_("Configs").c_str(), (const char*)ICON_FA_COGS, &this->window_subtab_config, 0);
			*/break;
		case 5:
			/*c_menu_elements::Instance().subtab(_xor_("Event Logging").c_str(), (const char*)ICON_FA_BOOK, &this->window_subtab_exec, 0);
			imsl;
			c_menu_elements::Instance().subtab(_xor_("Event Calling").c_str(), (const char*)ICON_FA_BOOK, &this->window_subtab_exec, 2);
			imsl;
			c_menu_elements::Instance().subtab(_xor_("Resources").c_str(), (const char*)ICON_FA_BOOK, &this->window_subtab_exec, 1);
			imsl;
			c_menu_elements::Instance().subtab(_xor_("Webviews").c_str(), (const char*)ICON_FA_BOOK, &this->window_subtab_exec, 3);
			*/break;
		case 6:
			/*c_menu_elements::Instance().subtab(_xor_("Scripts").c_str(), (const char*)ICON_FA_FILE, &this->window_subtab_admin, 0);
			imsl;
			c_menu_elements::Instance().subtab(_xor_("Editor").c_str(), (const char*)ICON_FA_NOTES_MEDICAL, &this->window_subtab_admin, 1);
			imsl;
			c_menu_elements::Instance().subtab(_xor_("Console").c_str(), (const char*)ICON_FA_CODE, &this->window_subtab_admin, 2);
			imsl;
			c_menu_elements::Instance().subtab(_xor_("Documentation").c_str(), (const char*)ICON_FA_NEWSPAPER, &this->window_subtab_admin, 3);
			*/break;
		}
	}
	c_menu_elements::Instance().endchild();
}

void Gui::create_items()
{
	ImGui::SetCursorPos({ 27, 98 });
	ImGui::BeginChild("MainContent", { 800, 402 }, false, ImGuiWindowFlags_NoBackground);
	{
		switch (this->window_tab)
		{
			/*case 0: render_home(); break;
			case 1: render_visuals(); break;
			case 2: render_aimings(); break;
			case 3: render_misc(); break;
			case 4: render_config(); break;
			case 5: render_files(); break;
			case 6: render_networking(); break;
			*/
		}
	}
	ImGui::EndChild();
}

const std::string current_time() {
	time_t now = time(0);
	struct tm tstruct;
	char buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%H:%M:%S %P", &tstruct);
	return buf;
}


void Gui::pre_init() {
	ImGuiIO& io = ImGui::GetIO();

	/*	ImFontConfig default_font_c;
		default_font_c.MergeMode = true; default_font_c.PixelSnapH = true;*/
	static const ImWchar ranges[] = {
		0x0020, 0x00FF, // Basic Latin + Latin Supplement
		0x2000, 0x206F, // General Punctuation
		0x3000, 0x30FF, // CJK Symbols and Punctuations, Hiragana, Katakana
		0x31F0, 0x31FF, // Katakana Phonetic Extensions
		0xFF00, 0xFFEF, // Half-width characters
		0x4e00, 0x9FAF, // CJK Ideograms
		0x0400, 0x052F, // Cyrillic + Cyrillic Supplement
		0x2DE0, 0x2DFF, // Cyrillic Extended-A
		0xA640, 0xA69F, // Cyrillic Extended-B
		0,
	};
	io.Fonts->AddFontFromMemoryCompressedTTF(sfpro_compressed_data, sfpro_compressed_size, 14 /* 13 */, nullptr, ranges);

	static const ImWchar icon_ranges[] = { ICON_MIN_FA, ICON_MAX_FA, 0 };
	ImFontConfig icons_config; icons_config.MergeMode = true; icons_config.PixelSnapH = true;
	io.Fonts->AddFontFromMemoryTTF(&faprolight, sizeof faprolight, 13, &icons_config, icon_ranges);

	this->title =
		io.Fonts->AddFontFromMemoryCompressedTTF(sfpro_compressed_data, sfpro_compressed_size, 16, NULL, ranges);

	this->title_small =
		io.Fonts->AddFontFromMemoryCompressedTTF(sfpro_compressed_data, sfpro_compressed_size, 14, NULL, ranges);
}

void Gui::init()
{
	if (this->bMenuOpen) {
		auto new_alpha = ImGui::GetStyle().Alpha + (0.1 * (60 / ImGui::GetIO().Framerate));
		if (new_alpha >= 1) ImGui::GetStyle().Alpha = 1;
		else ImGui::GetStyle().Alpha = new_alpha;
	}
	else
		ImGui::GetStyle().Alpha = 0;


	if (!this->bMenuOpen){
		return;
	}

	/*if (init_style) {
		create_styles();
		init_style = false;
	}*/

	ImGui::SetNextWindowSize(ImVec2(850, 540), ImGuiCond_Once);

	if (ImGui::Begin("nemoSDK", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar)) {
		this->window_position = ImGui::GetWindowPos();
		this->draw_list = ImGui::GetWindowDrawList();

		this->create_decorations();
		this->create_tabs();
		this->create_items();
	}
	ImGui::End();

}