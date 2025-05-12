# -*- coding: utf-8 -*-
from docx import Document
from docx.shared import Pt, RGBColor
from docx.oxml.ns import qn
from docx.enum.text import WD_PARAGRAPH_ALIGNMENT, WD_LINE_SPACING
from docx2pdf import convert

# Load the document
doc_path = "/Users/mel-mora/Desktop/BACK_TRACKING-exercices/22.docx"
doc = Document(doc_path)

# Define font settings function
def set_font(paragraph, font_name="Times New Roman", size=12, bold=False, color=None):
    for run in paragraph.runs:
        run.font.name = font_name
        run._element.rPr.rFonts.set(qn('w:eastAsia'), font_name)
        run.font.size = Pt(size)
        run.font.bold = bold
        if color:
            run.font.color.rgb = color

# Format all paragraphs and apply heading styles where relevant
for para in doc.paragraphs:
    text = para.text.strip().lower()
    is_heading = any(text.startswith(prefix) for prefix in [
        "introduction", "1.", "2.", "3.", "4.", "partie", "définition", "principes", "conclusion"
    ])

    # Apply font and spacing
    if is_heading:
        set_font(para, size=16, bold=True, color=RGBColor(31, 73, 125))  # dark blue
    else:
        set_font(para)

    para.paragraph_format.alignment = WD_PARAGRAPH_ALIGNMENT.JUSTIFY
    para.paragraph_format.space_before = Pt(6)
    para.paragraph_format.space_after = Pt(6)
    para.paragraph_format.line_spacing_rule = WD_LINE_SPACING.ONE_POINT_FIVE

# Save the modified document
modified_docx_path = "/Users/mel-mora/Desktop/BACK_TRACKING-exercices/22_modified.docx"
doc.save(modified_docx_path)

# Convert to PDF
modified_pdf_path = "/Users/mel-mora/Desktop/BACK_TRACKING-exercices/22_modified.pdf"
convert(modified_docx_path, modified_pdf_path)

print("PDF created at:", modified_pdf_path)
