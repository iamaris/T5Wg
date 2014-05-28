{
//=========Macro generated from canvas: c1/c1
//=========  (Tue May 27 13:18:01 2014) by ROOT version5.34/18
   TCanvas *c1 = new TCanvas("c1", "c1",11,55,700,500);
   c1->Range(-0.625,-4.839914,5.625,30.67426);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1F *h_dr = new TH1F("h_dr","deltaR",25,0,5);
   h_dr->SetBinContent(5,14.4);
   h_dr->SetBinContent(6,7.2);
   h_dr->SetBinContent(7,10.8);
   h_dr->SetBinContent(8,18);
   h_dr->SetBinContent(9,19.8);
   h_dr->SetBinContent(10,10.8);
   h_dr->SetBinContent(11,5.4);
   h_dr->SetBinContent(12,5.4);
   h_dr->SetBinContent(13,12.6);
   h_dr->SetBinContent(14,18);
   h_dr->SetBinContent(15,10.8);
   h_dr->SetBinContent(16,10.8);
   h_dr->SetBinContent(17,16.2);
   h_dr->SetBinContent(18,1.8);
   h_dr->SetBinContent(19,3.6);
   h_dr->SetBinContent(20,1.8);
   h_dr->SetBinError(5,5.091169);
   h_dr->SetBinError(6,3.6);
   h_dr->SetBinError(7,4.409082);
   h_dr->SetBinError(8,5.6921);
   h_dr->SetBinError(9,5.969925);
   h_dr->SetBinError(10,4.409082);
   h_dr->SetBinError(11,3.117691);
   h_dr->SetBinError(12,3.117691);
   h_dr->SetBinError(13,4.762352);
   h_dr->SetBinError(14,5.6921);
   h_dr->SetBinError(15,4.409082);
   h_dr->SetBinError(16,4.409082);
   h_dr->SetBinError(17,5.4);
   h_dr->SetBinError(18,1.8);
   h_dr->SetBinError(19,2.545584);
   h_dr->SetBinError(20,1.8);
   h_dr->SetEntries(93);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("h_dr");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 93     ");
   text = ptstats->AddText("Mean  =  2.171");
   text = ptstats->AddText("RMS   = 0.8179");
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
