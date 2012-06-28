<?php
  require('fpdf/fpdf.php');
  class PDF extends FPDF {
  	public $foo;
    public $logo = NULL;//'img.png';
    public $title = "Uclick.com";
    public $footer_txt;

    //Header for each Page
    function Header(){
      //Logo
      //Image(string file [, float x [, float y [, float w [, float h [, string type [, mixed link]]]]]])
      $this->Image($this->logo,10,6,60);
      //Set Header Font
      $this->SetFont('Arial','B', 16);
      //Move the title to the right to center it
      $this->cell(80);
      //Print Title
      $this->Cell(30,10,$this->title,1,0,'C');
      //spacing after header via line break
      $this->Ln(20);
      }
      //Footer for each page
      function Footer(){
        // Position at 1.5 cm from bottom
        $this->SetY(-15);
        // Arial italic 8
        $this->SetFont('Arial','I',8);
        // Page number
        $this->Cell(0,10,$this->footer_txt,0,0,'C');
      } 
  }

// Instanciation of inherited class
$pdf = new PDF();
//Tell it to count page number for us
$pdf->AliasNbPages();
//we need a page to put things on

$pdf-> footer_txt = 'Page '.$pdf->PageNo().'/{nb}';
$pdf->logo = 'click-realty-logo-1-with-effect.png';

$pdf->AddPage();
$pdf->SetFont('Times','',12);
//Content!
for($i=1;$i<=40;$i++)
    $pdf->Cell(0,10,'Printing line number '.$i,0,1);
//$pdf->Output('Test.pdf','D');
$pdf->Output('Test.pdf','D');
echo '<pre>' . $pdf->logo . '</pre><br />';