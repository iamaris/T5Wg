{
//=========Macro generated from canvas: c1/c1
//=========  (Tue May 27 13:18:32 2014) by ROOT version5.34/18
   TCanvas *c1 = new TCanvas("c1", "c1",11,55,700,500);
   c1->Range(-0.625,-1.632698,5.625,14.69429);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1F *h_dr = new TH1F("h_dr","deltaR",25,0,5);
   h_dr->SetBinContent(5,2.8);
   h_dr->SetBinContent(6,4.800001);
   h_dr->SetBinContent(7,5.200001);
   h_dr->SetBinContent(8,6.400001);
   h_dr->SetBinContent(9,4.800001);
   h_dr->SetBinContent(10,5.600001);
   h_dr->SetBinContent(11,5.200001);
   h_dr->SetBinContent(12,9.999999);
   h_dr->SetBinContent(13,7.600001);
   h_dr->SetBinContent(14,10.4);
   h_dr->SetBinContent(15,5.600001);
   h_dr->SetBinContent(16,8.400001);
   h_dr->SetBinContent(17,2.4);
   h_dr->SetBinContent(18,1.2);
   h_dr->SetBinContent(19,1.2);
   h_dr->SetBinError(5,1.058301);
   h_dr->SetBinError(6,1.385641);
   h_dr->SetBinError(7,1.442221);
   h_dr->SetBinError(8,1.6);
   h_dr->SetBinError(9,1.385641);
   h_dr->SetBinError(10,1.496663);
   h_dr->SetBinError(11,1.442221);
   h_dr->SetBinError(12,2);
   h_dr->SetBinError(13,1.74356);
   h_dr->SetBinError(14,2.039608);
   h_dr->SetBinError(15,1.496663);
   h_dr->SetBinError(16,1.83303);
   h_dr->SetBinError(17,0.9797959);
   h_dr->SetBinError(18,0.6928203);
   h_dr->SetBinError(19,0.6928203);
   h_dr->SetEntries(204);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("h_dr");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 204    ");
   text = ptstats->AddText("Mean  =  2.234");
   text = ptstats->AddText("RMS   = 0.7014");
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
