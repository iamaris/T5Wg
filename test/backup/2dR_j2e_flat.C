{
//=========Macro generated from canvas: Canvas_1/Canvas_1
//=========  (Sun May 25 22:30:06 2014) by ROOT version5.34/18
   TCanvas *Canvas_1 = new TCanvas("Canvas_1", "Canvas_1",11,55,700,500);
   Canvas_1->Range(-0.625,-28.10616,5.625,252.9554);
   Canvas_1->SetFillColor(0);
   Canvas_1->SetBorderMode(0);
   Canvas_1->SetBorderSize(2);
   Canvas_1->SetFrameBorderMode(0);
   Canvas_1->SetFrameBorderMode(0);
   
   TH1F *h_dr = new TH1F("h_dr","deltaR",25,0,5);
   h_dr->SetBinContent(5,53);
   h_dr->SetBinContent(6,45);
   h_dr->SetBinContent(7,50);
   h_dr->SetBinContent(8,80);
   h_dr->SetBinContent(9,70);
   h_dr->SetBinContent(10,64);
   h_dr->SetBinContent(11,67);
   h_dr->SetBinContent(12,78);
   h_dr->SetBinContent(13,98);
   h_dr->SetBinContent(14,126);
   h_dr->SetBinContent(15,117);
   h_dr->SetBinContent(16,200);
   h_dr->SetBinContent(17,81);
   h_dr->SetBinContent(18,46);
   h_dr->SetBinContent(19,30);
   h_dr->SetBinContent(20,10);
   h_dr->SetBinContent(21,1);
   h_dr->SetBinError(5,7.28011);
   h_dr->SetBinError(6,6.708204);
   h_dr->SetBinError(7,7.071068);
   h_dr->SetBinError(8,8.944272);
   h_dr->SetBinError(9,8.3666);
   h_dr->SetBinError(10,8);
   h_dr->SetBinError(11,8.185353);
   h_dr->SetBinError(12,8.831761);
   h_dr->SetBinError(13,9.899495);
   h_dr->SetBinError(14,11.22497);
   h_dr->SetBinError(15,10.81665);
   h_dr->SetBinError(16,14.14214);
   h_dr->SetBinError(17,9);
   h_dr->SetBinError(18,6.78233);
   h_dr->SetBinError(19,5.477226);
   h_dr->SetBinError(20,3.162278);
   h_dr->SetBinError(21,1);
   h_dr->SetEntries(1216);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("h_dr");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 1216   ");
   text = ptstats->AddText("Mean  =  2.439");
   text = ptstats->AddText("RMS   = 0.7644");
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
   Canvas_1->Modified();
   Canvas_1->cd();
   Canvas_1->SetSelected(Canvas_1);
}
