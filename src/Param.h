/*
 * Parameters
 *
 * Wang Lu
 * 2012.08.03
 */


#ifndef PARAM_H__
#define PARAM_H__

#include <string>

namespace pdf2htmlEX {

struct Param
{
    std::string www_path; // AI LABS PATCH ORIG 2015
    std::string manifest; // AI LABS PATCH: Allow setting of manifest option, to "manifest_standalone" or "manifest_transcludable" 2015

    // pages
    int first_page, last_page;

    // dimensions
    double zoom;
    double fit_width, fit_height;
    int use_cropbox;
    double h_dpi, v_dpi;

    // output
    int embed_css;
    int embed_font;
    int embed_image;
    int embed_javascript;
    int embed_outline;
    int split_pages;
    std::string dest_dir;
    std::string css_filename;
    std::string page_filename;
    std::string outline_filename;
    int process_nontext;
    int process_outline;
    int process_annotation;
    int process_form;
    int correct_text_visibility;
    int printing;
    int fallback;
    int tmp_file_size_limit;

    // fonts
    int embed_external_font;
    std::string font_format;
    int decompose_ligature;
    int auto_hint;
    std::string external_hint_tool;
    int stretch_narrow_glyph;
    int squeeze_wide_glyph;
    int override_fstype;
    int process_type3;
    // AI LABS PATCH 1/14/2016: Will cause skipping of fonts which have glyph problems.
    // Why this is necessary when viewing of user-provided PDFs must be supported:
    // Fonts with missing ligatures cause certain two-letter permutations to end up removed from rendered text,
    // like "tt" and "ff".
    // This is done by running PSTValid() from Fontforge in lookups.c. Because we don't want two forks, we located that code in ffw.c so it is accessible to this program.
    // By detecting these table lookup problems in the font, we can disable the font so the text will at least display.
    // FUTURE: Keep text size consistent by emulating the font's em size in generic san-serif substituted font using simple rule.
    int validate_font_glyphtable;

    // text
    double h_eps, v_eps;
    double space_threshold;
    double font_size_multiplier;
    int space_as_offset;
    int tounicode;
    int optimize_text;

    // background image
    std::string bg_format;
    int svg_node_count_limit;
    int svg_embed_bitmap;

    // encryption
    std::string owner_password, user_password;
    int no_drm;

    // misc.
    int clean_tmp;
    std::string data_dir;
    std::string tmp_dir;
    int debug;
    int proof;

    std::string input_filename, output_filename;
};

} // namespace pdf2htmlEX

#endif //PARAM_h__
