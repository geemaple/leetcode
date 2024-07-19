import sys
import fitz  # PyMuPDF
from urllib.parse import urlparse
from collections import Counter, defaultdict

def extract_links(pdf_path):
    # Open the PDF file
    pdf_document = fitz.open(pdf_path)
    links = []

    # Iterate through each page
    for page_num in range(len(pdf_document)):
        page = pdf_document.load_page(page_num)  # Load the page
        link_dict = page.get_links()  # Get the links on the page

        # Iterate through each link and extract the URI
        for link in link_dict:
            if 'uri' in link:
                links.append(link['uri'])

    return links

def main():
    if len(sys.argv) != 2:
        print("Usage: python pdflink.py <file_path>")
        sys.exit(1)

    pdf_path = sys.argv[1]

    # Extract links
    extracted_links = extract_links(pdf_path)
    counter = defaultdict(lambda: 1)

    for link in extracted_links:
        domain = urlparse(link).netloc
        print(f"{counter[domain]}: {link}")
        counter[domain] += 1

if __name__ == "__main__":
    main()