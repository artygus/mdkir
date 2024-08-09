class Mdkir < Formula
  version "0.1"
  sha256 "2273a16f3ba6977ac1798a3082e2654040ec46c4b84a32d136ba4ba69a3adc86"
  url "https://github.com/artygus/mdkir/archive/refs/tags/v#{version}.tar.gz"
  desc "Prints Kir if you type mdkir instead of mkdir"
  license "MIT"
  head "https://github.com/artygus/mdkir.git", branch: "main"

  uses_from_macos "ncurses"

  def install
    system "make", "-e"
    bin.install "mdkir"
  end
end
