{
//=========Macro generated from canvas: c1/c1
//=========  (Tue May 27 13:17:07 2014) by ROOT version5.34/18
   TCanvas *c1 = new TCanvas("c1", "c1",11,55,700,500);
   c1->Range(-0.625,-3.255811,5.625,29.3023);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1F *h_dr = new TH1F("h_dr","deltaR",25,0,5);
   h_dr->SetBinContent(5,3.654732);
   h_dr->SetBinContent(6,3.011983);
   h_dr->SetBinContent(7,3.788429);
   h_dr->SetBinContent(8,5.195808);
   h_dr->SetBinContent(9,0.8984928);
   h_dr->SetBinContent(10,2.781039);
   h_dr->SetBinContent(11,7.057539);
   h_dr->SetBinContent(12,9.007457);
   h_dr->SetBinContent(13,6.783442);
   h_dr->SetBinContent(14,11.50841);
   h_dr->SetBinContent(15,14.96124);
   h_dr->SetBinContent(16,22.22271);
   h_dr->SetBinContent(17,7.979795);
   h_dr->SetBinContent(18,3.61358);
   h_dr->SetBinContent(19,0.6396921);
   h_dr->SetBinContent(20,0.2739261);
   h_dr->SetBinError(5,1.058676);
   h_dr->SetBinError(6,0.9596684);
   h_dr->SetBinError(7,1.09663);
   h_dr->SetBinError(8,1.268534);
   h_dr->SetBinError(9,0.5202898);
   h_dr->SetBinError(10,0.9309564);
   h_dr->SetBinError(11,1.476392);
   h_dr->SetBinError(12,1.656085);
   h_dr->SetBinError(13,1.455595);
   h_dr->SetBinError(14,1.855966);
   h_dr->SetBinError(15,2.089928);
   h_dr->SetBinError(16,2.583468);
   h_dr->SetBinError(17,1.519719);
   h_dr->SetBinError(18,1.050083);
   h_dr->SetBinError(19,0.45386);
   h_dr->SetBinError(20,0.2739261);
   h_dr->SetEntries(347);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("h_dr");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 347    ");
   text = ptstats->AddText("Mean  =  2.555");
   text = ptstats->AddText("RMS   = 0.6981");
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
