{
//=========Macro generated from canvas: c1/c1
//=========  (Tue May 27 13:12:53 2014) by ROOT version5.34/18
   TCanvas *c1 = new TCanvas("c1", "c1",11,55,700,500);
   c1->Range(-0.625,-1.126448,5.625,10.13803);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1F *h_dr = new TH1F("h_dr","deltaR",25,0,5);
   h_dr->SetBinContent(5,3.858765);
   h_dr->SetBinContent(6,2.807979);
   h_dr->SetBinContent(7,2.668612);
   h_dr->SetBinContent(8,3.050512);
   h_dr->SetBinContent(9,2.883728);
   h_dr->SetBinContent(10,2.853488);
   h_dr->SetBinContent(11,2.964348);
   h_dr->SetBinContent(12,3.398488);
   h_dr->SetBinContent(13,3.879837);
   h_dr->SetBinContent(14,4.82323);
   h_dr->SetBinContent(15,5.170967);
   h_dr->SetBinContent(16,8.115461);
   h_dr->SetBinContent(17,2.955219);
   h_dr->SetBinContent(18,1.668686);
   h_dr->SetBinContent(19,0.9947714);
   h_dr->SetBinContent(20,0.2682095);
   h_dr->SetBinContent(21,0.05393336);
   h_dr->SetBinError(5,0.3227009);
   h_dr->SetBinError(6,0.2753577);
   h_dr->SetBinError(7,0.268217);
   h_dr->SetBinError(8,0.2869839);
   h_dr->SetBinError(9,0.2787926);
   h_dr->SetBinError(10,0.2771649);
   h_dr->SetBinError(11,0.2826499);
   h_dr->SetBinError(12,0.3027787);
   h_dr->SetBinError(13,0.3233339);
   h_dr->SetBinError(14,0.3605211);
   h_dr->SetBinError(15,0.3731978);
   h_dr->SetBinError(16,0.4670021);
   h_dr->SetBinError(17,0.2817741);
   h_dr->SetBinError(18,0.2119307);
   h_dr->SetBinError(19,0.1635438);
   h_dr->SetBinError(20,0.08481543);
   h_dr->SetBinError(21,0.03813738);
   h_dr->SetEntries(1946);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("h_dr");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 1946   ");
   text = ptstats->AddText("Mean  =  2.333");
   text = ptstats->AddText("RMS   = 0.8062");
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
