{
//=========Macro generated from canvas: c1/c1
//=========  (Sun May 25 21:23:16 2014) by ROOT version5.34/18
   TCanvas *c1 = new TCanvas("c1", "c1",11,55,700,500);
   c1->Range(-0.625,-15.53899,5.625,139.8509);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1F *h_dr = new TH1F("h_dr","deltaR",25,0,5);
   h_dr->SetBinContent(5,103);
   h_dr->SetBinContent(6,67);
   h_dr->SetBinContent(7,55);
   h_dr->SetBinContent(8,39);
   h_dr->SetBinContent(9,39);
   h_dr->SetBinContent(10,46);
   h_dr->SetBinContent(11,46);
   h_dr->SetBinContent(12,51);
   h_dr->SetBinContent(13,50);
   h_dr->SetBinContent(14,56);
   h_dr->SetBinContent(15,78);
   h_dr->SetBinContent(16,108);
   h_dr->SetBinContent(17,31);
   h_dr->SetBinContent(18,16);
   h_dr->SetBinContent(19,7);
   h_dr->SetBinContent(21,1);
   h_dr->SetBinError(5,10.14889);
   h_dr->SetBinError(6,8.185353);
   h_dr->SetBinError(7,7.416198);
   h_dr->SetBinError(8,6.244998);
   h_dr->SetBinError(9,6.244998);
   h_dr->SetBinError(10,6.78233);
   h_dr->SetBinError(11,6.78233);
   h_dr->SetBinError(12,7.141428);
   h_dr->SetBinError(13,7.071068);
   h_dr->SetBinError(14,7.483315);
   h_dr->SetBinError(15,8.831761);
   h_dr->SetBinError(16,10.3923);
   h_dr->SetBinError(17,5.567764);
   h_dr->SetBinError(18,4);
   h_dr->SetBinError(19,2.645751);
   h_dr->SetBinError(21,1);
   h_dr->SetEntries(793);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("h_dr");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 793    ");
   text = ptstats->AddText("Mean  =   2.13");
   text = ptstats->AddText("RMS   = 0.8443");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   h_dr->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(h_dr);

   Int_t ci;   // for color index setting
   ci = TColor::GetColor("#000099");
   h_dr->SetLineColor(ci);
   h_dr->GetXaxis()->SetLabelFont(42);
   h_dr->GetXaxis()->SetLabelSize(0.035);
   h_dr->GetXaxis()->SetTitleSize(0.035);
   h_dr->GetXaxis()->SetTitleFont(42);
   h_dr->GetYaxis()->SetLabelFont(42);
   h_dr->GetYaxis()->SetLabelSize(0.035);
   h_dr->GetYaxis()->SetTitleSize(0.035);
   h_dr->GetYaxis()->SetTitleFont(42);
   h_dr->GetZaxis()->SetLabelFont(42);
   h_dr->GetZaxis()->SetLabelSize(0.035);
   h_dr->GetZaxis()->SetTitleSize(0.035);
   h_dr->GetZaxis()->SetTitleFont(42);
   h_dr->Draw("");
   
   TPaveText *pt = new TPaveText(0.4375575,0.94,0.5624425,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("deltaR");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
