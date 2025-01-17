﻿#ifndef __LCUI_TEXTSTYLE_H__
#define __LCUI_TEXTSTYLE_H__

LCUI_BEGIN_HEADER

typedef enum _font_style
{ 
	FONT_STYLE_NORMAL = 0, 
	FONT_STYLE_ITALIC = 1, 
	FONT_STYLE_OBIQUE = 2 
}
enum_font_style;

typedef enum _font_weight
{
	FONT_WEIGHT_NORMAL	= 0,
	FONT_WEIGHT_BOLD	= 1 
} 
enum_font_weight;

typedef enum _font_decoration
{
	FONT_DECORATION_NONE		= 0,	/* 无装饰 */
	FONT_DECORATION_BLINK		= 1,	/* 闪烁 */
	FONT_DECORATION_UNDERLINE	= 2,	/* 下划线 */
	FONT_DECORATION_LINE_THROUGH	= 3,	/* 贯穿线 */
	FONT_DECORATION_OVERLINE	= 4	/* 上划线 */
}
enum_font_decoration; 


typedef struct _LCUI_TextStyle
{
	LCUI_BOOL _family:1;
	LCUI_BOOL _style:1;
	LCUI_BOOL _weight:1;
	LCUI_BOOL _decoration:1;
	LCUI_BOOL _back_color:1;
	LCUI_BOOL _fore_color:1;
	LCUI_BOOL _pixel_size:1;
	
	int font_id;
	enum_font_style	style		:3;
	enum_font_weight	weight		:3;
	enum_font_decoration	decoration	:4;
	
	LCUI_RGB fore_color;
	LCUI_RGB back_color;
	
	int pixel_size;	
}
LCUI_TextStyle;

typedef enum {
	TAG_ID_FAMILY = 0,
	TAG_ID_STYLE = 1,
	TAG_ID_WIEGHT = 2,
	TAG_ID_DECORATION = 3,
	TAG_ID_SIZE = 4,
	TAG_ID_COLOR = 5
} StyleTag_ID;

typedef struct {
	StyleTag_ID tag;
	void *style;
} StyleTag_Data;


/* 初始化字体样式数据 */
LCUI_API void TextStyle_Init ( LCUI_TextStyle *data );

/* 设置字体族 */
LCUI_API void TextStyle_FontFamily( LCUI_TextStyle *style, const char *fontfamily );

/* 设置字体族ID */
LCUI_API void TextStyle_FontFamilyID( LCUI_TextStyle *style, int id );

/* 设置字体大小 */
LCUI_API void TextStyle_FontSize( LCUI_TextStyle *style, int fontsize );

/* 设置字体颜色 */
LCUI_API void TextStyle_FontColor( LCUI_TextStyle *style, LCUI_RGB color );

/* 设置字体背景颜色 */
LCUI_API void TextStyle_FontBackColor( LCUI_TextStyle *style, LCUI_RGB color );

/* 设置字体样式 */
LCUI_API void TextStyle_FontStyle( LCUI_TextStyle *style, enum_font_style fontstyle );

LCUI_API void TextStyle_FontWeight( LCUI_TextStyle *style, enum_font_weight fontweight );

/* 设置字体下划线 */
LCUI_API void TextStyle_FontDecoration( LCUI_TextStyle *style, enum_font_decoration decoration );

LCUI_API int TextStyle_Cmp( LCUI_TextStyle *a, LCUI_TextStyle *b );

/*-------------------------- StyleTag --------------------------------*/
#define MAX_TAG_NUM 2

/* 初始化样式标签库 */
LCUI_API void StyleTag_Init( LCUI_Queue *tags );

/* 添加样式标签 */
LCUI_API int StyleTag_Add( LCUI_Queue *tags, StyleTag_Data *data );

/* 获取当前的样式数据 */
LCUI_API LCUI_TextStyle* StyleTag_GetCurrentStyle ( LCUI_Queue *tags );

/* 处理样式标签 */
LCUI_API wchar_t* StyleTag_ProcessTag( LCUI_Queue *tags, wchar_t *str );

/* 处理样式结束标签 */
LCUI_API wchar_t*
StyleTag_ProcessEndingTag( LCUI_Queue *tags, wchar_t *str );

/*------------------------- End StyleTag -----------------------------*/

LCUI_END_HEADER

#endif
